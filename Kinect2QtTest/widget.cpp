#include "widget.h"
#include "ui_widget.h"

#include <Kinect2SKDInc/Kinect.h>
#include <OpenCVInc/opencv/highgui.h>
#include <OpenCVInc/opencv/cv.h>
#include <opencv2/imgproc.hpp>//cvtColor
#include <opencv2/opencv.hpp>//equalizeHist
#include <windows.h>
#include <qDebug>
#include <QDateTime>
#include <QFileDialog>

#include <QSettings>  //读写ini文件。

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textBrowser->document()->setMaximumBlockCount (5);

    ReadIni();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerUpadate()));
    //timer->start(100);

    m_pKinectSensor= NULL;
    m_pDepthFrameReader= NULL;
    pDepthFrameSource = NULL;
    pInfraredFrameSource = NULL;
    InfraredFrameReader= NULL;
    ColorFrameReader = NULL;
    ColorFrameSource = NULL;
    FrameDescription = NULL;

    TimerCount=0;


    GetDefaultKinectSensor(&m_pKinectSensor);


    m_pKinectSensor->Open();    //打开传感器




    m_pKinectSensor->get_DepthFrameSource(&pDepthFrameSource);

    m_pKinectSensor->get_InfraredFrameSource(&pInfraredFrameSource);

    m_pKinectSensor->get_ColorFrameSource(&ColorFrameSource);

    pDepthFrameSource->OpenReader(&m_pDepthFrameReader);

    pInfraredFrameSource->OpenReader(&InfraredFrameReader);

    ColorFrameSource->OpenReader(&ColorFrameReader);

}

Widget::~Widget()
{
    delete ui;
}

void  Widget::TimerUpadate()
{
        IInfraredFrame*       InfraredFrame = NULL;
        IDepthFrame*          pDepthFrame = NULL;
        IColorFrame*          pColorFrame = NULL;

        /**********************************************************红外图*********************************************************/
        while (InfraredFrame == NULL)
        {
            InfraredFrameReader->AcquireLatestFrame(&InfraredFrame);
        }
        InfraredFrame->get_FrameDescription(&FrameDescription);
        int nWidth, nHeight;

        FrameDescription->get_Width(&nWidth);
        FrameDescription->get_Height(&nHeight);

        cv::Mat InfraredImg(nHeight, nWidth, CV_16UC1);
        InfraredFrame->CopyFrameDataToArray(nWidth * nHeight, (UINT16 *)InfraredImg.data);
        /**********************************************************彩色图*********************************************************/
        while (pColorFrame == NULL)
        {
            ColorFrameReader->AcquireLatestFrame(&pColorFrame);
        }
        pColorFrame->get_FrameDescription(&FrameDescription);
        int CWidth, CHeight;

        FrameDescription->get_Width(&CWidth);
        FrameDescription->get_Height(&CHeight);

        cv::Mat ColorImg(CHeight, CWidth, CV_8UC4);
        pColorFrame->CopyConvertedFrameDataToArray(CWidth * CHeight * 4, (BYTE *)ColorImg.data, ColorImageFormat_Bgra);
        /**********************************************************深度图*********************************************************/
        while (pDepthFrame == NULL)
        {
            m_pDepthFrameReader->AcquireLatestFrame(&pDepthFrame);
        }
        pDepthFrameSource->get_FrameDescription(&FrameDescription);

        int depth_width, depth_height;

        FrameDescription->get_Width(&depth_width);
        FrameDescription->get_Height(&depth_height);

        cv::Mat DepthImg(depth_height, depth_width, CV_16UC1);
        pDepthFrame->CopyFrameDataToArray(depth_height * depth_width, (UINT16 *)DepthImg.data);

        /***************************************保存数据******************************/

         if(TimerCount>=StoreTimer)
         {
             TimerCount=0;

             cv::Mat mColorImg;
             cv::Mat mDepthImg;
             mColorImg=ColorImg;
             mDepthImg=DepthImg;
             GetCouldAndStoreAll(mDepthImg,mColorImg,InfraredImg,depth_width, depth_height);
         }

         TimerCount +=100;

        /*********************************************************************/
        DepthImg.convertTo(DepthImg, CV_8UC1, 255.0 / 4500);        //转换为8位图像
        cv::equalizeHist(DepthImg, DepthImg); //均衡化

        InfraredImg.convertTo(InfraredImg, CV_8UC1, 255.0 / 4500);        //红外转换为8位图像//*************
        cv::equalizeHist(InfraredImg, InfraredImg); //均衡化//*************

        /**********************************************************显示*********************************************************/

        LableShowMat(ui->label, ColorImg);
        LableShowMat(ui->label_2, DepthImg);
        LableShowMat(ui->label_3, InfraredImg);






        DepthImg.release();
        ColorImg.release();
        InfraredImg.release();

        if (pDepthFrame)
            pDepthFrame->Release();
        if (pColorFrame)
            pColorFrame->Release();
        if (InfraredFrame)
            InfraredFrame->Release();




}

void Widget::LableShowMat(QLabel *label, cv::Mat mat)
{
    QImage image=MatToQImage(mat);


    QImage image2 = image.scaled(label->width(), label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); // 饱满填充

    label->setPixmap(QPixmap::fromImage(image2));

}

QImage Widget::MatToQImage(const cv::Mat mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }

}

void Widget::GetCouldAndStoreAll(cv::Mat depth_mat,cv::Mat color_mat,cv::Mat hongwai_mat,
                                 int depth_width, int depth_height)
{
    ICoordinateMapper*      m_pCoordinateMapper=NULL;
    m_pKinectSensor->get_CoordinateMapper(&m_pCoordinateMapper);

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);

    ColorSpacePoint* depth2rgb = new ColorSpacePoint[512 * 424];
    CameraSpacePoint* depth2xyz = new CameraSpacePoint[512 * 424];
    m_pCoordinateMapper->MapDepthFrameToColorSpace(512 * 424, (UINT16 *)depth_mat.data, 512 * 424, depth2rgb);
    m_pCoordinateMapper->MapDepthFrameToCameraSpace(512 * 424, (UINT16 *)depth_mat.data, 512 * 424, depth2xyz);//深度图到相机三维空间的映射

    float maxX = depth2xyz[0].X, maxY = depth2xyz[0].Y, maxZ = depth2xyz[0].Z;
    float minX = depth2xyz[0].X, minY = depth2xyz[0].Y, minZ = depth2xyz[0].Z;

    for (size_t i = 0; i < depth_width; i++)
            {
                for (size_t j = 0; j < depth_height; j++)
                {
                    pcl::PointXYZRGBA pointTemp;
                    if (depth2xyz[i + j*depth_width].Z > 0.5&&depth2rgb[i + j*depth_width].X<1920 && depth2rgb[i + j*depth_width].X>0 && depth2rgb[i + j*depth_width].Y<1080 && depth2rgb[i + j*depth_width].Y>0)
                    {
                        pointTemp.x = -depth2xyz[i + j*depth_width].X;
                        if (depth2xyz[i + j*depth_width].X > maxX) maxX = -depth2xyz[i + j*depth_width].X;
                        if (depth2xyz[i + j*depth_width].X < minX) minX = -depth2xyz[i + j*depth_width].X;
                        pointTemp.y = depth2xyz[i + j*depth_width].Y;
                        if (depth2xyz[i + j*depth_width].Y > maxY) maxY = depth2xyz[i + j*depth_width].Y;
                        if (depth2xyz[i + j*depth_width].Y < minY) minY = depth2xyz[i + j*depth_width].Y;
                        pointTemp.z = depth2xyz[i + j*depth_width].Z;
                        if (depth2xyz[i + j*depth_width].Z != 0.0)
                        {
                            if (depth2xyz[i + j*depth_width].Z > maxZ) maxZ = depth2xyz[i + j*depth_width].Z;
                            if (depth2xyz[i + j*depth_width].Z < minZ) minZ = depth2xyz[i + j*depth_width].Z;
                        }
                        pointTemp.b = color_mat.at<cv::Vec4b>(depth2rgb[i + j*depth_width].Y, depth2rgb[i + j*depth_width].X)[0];
                        pointTemp.g = color_mat.at<cv::Vec4b>(depth2rgb[i + j*depth_width].Y, depth2rgb[i + j*depth_width].X)[1];
                        pointTemp.r = color_mat.at<cv::Vec4b>(depth2rgb[i + j*depth_width].Y, depth2rgb[i + j*depth_width].X)[2];
                        pointTemp.a = color_mat.at<cv::Vec4b>(depth2rgb[i + j*depth_width].Y, depth2rgb[i + j*depth_width].X)[3];
                        cloud->push_back(pointTemp);
                    }

                }

            }

            QString path=StorePath;
            QDateTime datetime;
            QString timestr=datetime.currentDateTime().toString("yyyyMMdd-HH-mm-ss");

            pcl::io::savePCDFileASCII<pcl::PointXYZRGBA>((path+"/PointCloud/" + timestr + ".pcd").toStdString(),*cloud);
            cv::imwrite((path+"/RGB/"+timestr+".jpg").toStdString(), color_mat);
            cv::imwrite((path+"/Depth/"+timestr+".jpg").toStdString(), depth_mat);
            cv::imwrite((path+"/Infrared/"+timestr+".jpg").toStdString(), hongwai_mat);

            ui->textBrowser->append(timestr+"  Saved");
}



void Widget::on_pushButton_clicked()//选择储存文件夹
{
    QString file_path = QFileDialog::getExistingDirectory(this, "请选择文件路径...", "./");
    if(!file_path.isEmpty())
    {
        QSettings *configIni = new QSettings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
        configIni->setValue("/store_add/Path", file_path);
        StorePath=file_path;
        ui->label_5->setText("当前储存目录:  "+StorePath);
        PathBuQuan(StorePath);
        delete  configIni;
    }

}

void Widget::ReadIni()
{
    QSettings *configIni = new QSettings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
    StorePath=configIni->value(   "/store_add/Path"   ).toString();
    ui->label_5->setText("当前储存目录:  "+StorePath);
    PathBuQuan(StorePath);

    StoreTimer=configIni->value(   "/timer/t"   ).toInt();
    ui->lineEdit->setText(QString::number(StoreTimer));
    delete  configIni;

}


void Widget::on_pushButton_2_clicked()//修改储存周期
{
    StoreTimer=ui->lineEdit->text().toInt();
    QSettings *configIni = new QSettings(QCoreApplication::applicationDirPath() + "/config.ini", QSettings::IniFormat);
    configIni->setValue("/timer/t",QString::number(StoreTimer));

    delete  configIni;

}


void Widget::PathBuQuan(QString path)//文件夹补全
{

    QDir dir(path);
    QDir dir1(path+"/RGB");
    QDir dir2(path+"/Depth");
    QDir dir3(path+"/Infrared");
    QDir dir4(path+"/PointCloud");

    if(!dir.exists())     dir.mkpath(path);
    if(!dir1.exists())     dir1.mkpath(path+"/RGB");
    if(!dir2.exists())     dir2.mkpath(path+"/Depth");
    if(!dir3.exists())     dir3.mkpath(path+"/Infrared");
    if(!dir4.exists())     dir4.mkpath(path+"/PointCloud");

}

void Widget::on_pushButton_3_clicked()//Start
{
    if(ui->pushButton_3->text()=="Start")
    {
        PathBuQuan(StorePath);
        timer->start(100);
        ui->pushButton_3->setText("Stop");
    }
    else
    {
        timer->stop();
        ui->pushButton_3->setText("Start");
    }

}
