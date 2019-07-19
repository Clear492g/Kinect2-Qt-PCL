#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <Kinect2SKDInc/Kinect.h>
#include <OpenCVInc/opencv/highgui.h>
#include <OpenCVInc/opencv/cv.h>

#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>

#include <QSettings>  //读写ini文件。

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void LableShowMat(QLabel *label, cv::Mat mat);
    QImage MatToQImage(const cv::Mat mat) ;



    IKinectSensor*          m_pKinectSensor;

    IDepthFrameReader*      m_pDepthFrameReader;
    IDepthFrameSource*      pDepthFrameSource ;
    IInfraredFrameSource*   pInfraredFrameSource ;
    IInfraredFrameReader*   InfraredFrameReader;

    IColorFrameReader*      ColorFrameReader ;
    IColorFrameSource*      ColorFrameSource ;

    IFrameDescription*      FrameDescription ;

    int StoreTimer;
    int TimerCount;
    QString StorePath;


    void GetCouldAndStoreAll(cv::Mat depth_mat,cv::Mat color_mat,cv::Mat hongwai_mat,int depth_width, int depth_height);

    void ReadIni();
    void PathBuQuan(QString path);

    QTimer *timer;





private:
    Ui::Widget *ui;

private slots:
    void TimerUpadate();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // WIDGET_H
