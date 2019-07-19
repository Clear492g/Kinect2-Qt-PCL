#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}



//CONFIG(debug,debug|release):
//{LIBS += -LC:\Program Files\PCL 1.8.0/lib\
//#        -lpcl_apps_debug\
//-lpcl_common_debug\
//-lpcl_features_debug\
//-lpcl_filters_debug\
//-lpcl_io_debug\
//-lpcl_io_ply_debug\
//-lpcl_kdtree_debug\
//-lpcl_keypoints_debug\
//-lpcl_ml_debug\
//-lpcl_octree_debug\
//-lpcl_outofcore_debug\
//-lpcl_people_debug\
//-lpcl_recognition_debug\
//-lpcl_registration_debug\
//-lpcl_sample_consensus_debug\
//-lpcl_search_debug\
//-lpcl_segmentation_debug\
//#        -lpcl_simulation_debug\
//-lpcl_stereo_debug\
//-lpcl_surface_debug\
//-lpcl_tracking_debug\
//-lpcl_visualization_debug\

//LIBS += -LC:\Program Files\PCL 1.8.0/3rdParty/Boost/lib\
//-llibboost_atomic-vc140-mt-gd-1_61\
//-llibboost_chrono-vc140-mt-gd-1_61\
//-llibboost_container-vc140-mt-gd-1_61\
//-llibboost_context-vc140-mt-gd-1_61\
//-llibboost_coroutine-vc140-mt-gd-1_61\
//-llibboost_date_time-vc140-mt-gd-1_61\
//-llibboost_exception-vc140-mt-gd-1_61\
//-llibboost_filesystem-vc140-mt-gd-1_61\
//-llibboost_graph-vc140-mt-gd-1_61\
//-llibboost_iostreams-vc140-mt-gd-1_61\
//-llibboost_locale-vc140-mt-gd-1_61\
//-llibboost_log-vc140-mt-gd-1_61\
//-llibboost_log_setup-vc140-mt-gd-1_61\
//-llibboost_math_c99-vc140-mt-gd-1_61\
//-llibboost_math_c99f-vc140-mt-gd-1_61\
//-llibboost_math_c99l-vc140-mt-gd-1_61\
//-llibboost_math_tr1-vc140-mt-gd-1_61\
//-llibboost_math_tr1f-vc140-mt-gd-1_61\
//-llibboost_math_tr1l-vc140-mt-gd-1_61\
//-llibboost_mpi-vc140-mt-gd-1_61\
//-llibboost_prg_exec_monitor-vc140-mt-gd-1_61\
//-llibboost_program_options-vc140-mt-gd-1_61\
//-llibboost_random-vc140-mt-gd-1_61\
//-llibboost_regex-vc140-mt-gd-1_61\
//-llibboost_serialization-vc140-mt-gd-1_61\
//-llibboost_signals-vc140-mt-gd-1_61\
//-llibboost_system-vc140-mt-gd-1_61\
//-llibboost_test_exec_monitor-vc140-mt-gd-1_61\
//-llibboost_thread-vc140-mt-gd-1_61\
//-llibboost_timer-vc140-mt-gd-1_61\
//-llibboost_unit_test_framework-vc140-mt-gd-1_61\
//-llibboost_wave-vc140-mt-gd-1_61\
//-llibboost_wserialization-vc140-mt-gd-1_61

//LIBS += -LC:\Program Files\PCL 1.8.0/3rdParty/FLANN/lib\
//-lflann-gd\
//-lflann_cpp_s-gd\
//-lflann_s-gd

//LIBS += -LC:\Program Files\OpenNI2\Lib\
//-lOpenNI2

//LIBS += -LC:\Program Files\PCL 1.8.0/3rdParty/Qhull/lib\
//-lqhull-gd\
//-lqhullcpp-gd\
//-lqhullstatic-gd\
//-lqhullstatic_r-gd\
//-lqhull_p-gd\
//-lqhull_r-gd

//LIBS += -LC:\Program Files\PCL 1.8.0\3rdParty\VTK\lib\
//-lvtkalglib-7.0-gd\
//-lvtkChartsCore-7.0-gd\
//-lvtkCommonColor-7.0-gd\
//-lvtkCommonComputationalGeometry-7.0-gd\
//-lvtkCommonCore-7.0-gd\
//-lvtkCommonDataModel-7.0-gd\
//-lvtkCommonExecutionModel-7.0-gd\
//-lvtkCommonMath-7.0-gd\
//-lvtkCommonMisc-7.0-gd\
//-lvtkCommonSystem-7.0-gd\
//-lvtkCommonTransforms-7.0-gd\
//-lvtkDICOMParser-7.0-gd\
//-lvtkDomainsChemistry-7.0-gd\
//-lvtkDomainsChemistryOpenGL2-7.0-gd\
//-lvtkexoIIc-7.0-gd\
//-lvtkexpat-7.0-gd\
//-lvtkFiltersAMR-7.0-gd\
//-lvtkFiltersCore-7.0-gd\
//-lvtkFiltersExtraction-7.0-gd\
//-lvtkFiltersFlowPaths-7.0-gd\
//-lvtkFiltersGeneral-7.0-gd\
//-lvtkFiltersGeneric-7.0-gd\
//-lvtkFiltersGeometry-7.0-gd\
//-lvtkFiltersHybrid-7.0-gd\
//-lvtkFiltersHyperTree-7.0-gd\
//-lvtkFiltersImaging-7.0-gd\
//-lvtkFiltersModeling-7.0-gd\
//-lvtkFiltersParallel-7.0-gd\
//-lvtkFiltersParallelImaging-7.0-gd\
//-lvtkFiltersProgrammable-7.0-gd\
//-lvtkFiltersSelection-7.0-gd\
//-lvtkFiltersSMP-7.0-gd\
//-lvtkFiltersSources-7.0-gd\
//-lvtkFiltersStatistics-7.0-gd\
//-lvtkFiltersTexture-7.0-gd\
//-lvtkFiltersVerdict-7.0-gd\
//-lvtkfreetype-7.0-gd\
//-lvtkGeovisCore-7.0-gd\
//-lvtkglew-7.0-gd\
//-lvtkGUISupportQt-7.0-gd\
//-lvtkGUISupportQtSQL-7.0-gd\
//-lvtkhdf5-7.0-gd\
//-lvtkhdf5_hl-7.0-gd\
//-lvtkImagingColor-7.0-gd\
//-lvtkImagingCore-7.0-gd\
//-lvtkImagingFourier-7.0-gd\
//-lvtkImagingGeneral-7.0-gd\
//-lvtkImagingHybrid-7.0-gd\
//-lvtkImagingMath-7.0-gd\
//-lvtkImagingMorphological-7.0-gd\
//-lvtkImagingSources-7.0-gd\
//-lvtkImagingStatistics-7.0-gd\
//-lvtkImagingStencil-7.0-gd\
//-lvtkInfovisCore-7.0-gd\
//-lvtkInfovisLayout-7.0-gd\
//-lvtkInteractionImage-7.0-gd\
//-lvtkInteractionStyle-7.0-gd\
//-lvtkInteractionWidgets-7.0-gd\
//-lvtkIOAMR-7.0-gd\
//-lvtkIOCore-7.0-gd\
//-lvtkIOEnSight-7.0-gd\
//-lvtkIOExodus-7.0-gd\
//-lvtkIOExport-7.0-gd\
//-lvtkIOGeometry-7.0-gd\
//-lvtkIOImage-7.0-gd\
//-lvtkIOImport-7.0-gd\
//-lvtkIOInfovis-7.0-gd\
//-lvtkIOLegacy-7.0-gd\
//-lvtkIOLSDyna-7.0-gd\
//-lvtkIOMINC-7.0-gd\
//-lvtkIOMovie-7.0-gd\
//-lvtkIONetCDF-7.0-gd\
//-lvtkIOParallel-7.0-gd\
//-lvtkIOParallelXML-7.0-gd\
//-lvtkIOPLY-7.0-gd\
//-lvtkIOSQL-7.0-gd\
//-lvtkIOVideo-7.0-gd\
//-lvtkIOXML-7.0-gd\
//-lvtkIOXMLParser-7.0-gd\
//-lvtkjpeg-7.0-gd\
//-lvtkjsoncpp-7.0-gd\
//-lvtklibxml2-7.0-gd\
//-lvtkmetaio-7.0-gd\
//-lvtkNetCDF-7.0-gd\
//-lvtkNetCDF_cxx-7.0-gd\
//-lvtkoggtheora-7.0-gd\
//-lvtkParallelCore-7.0-gd\
//-lvtkpng-7.0-gd\
//-lvtkproj4-7.0-gd\
//-lvtkRenderingAnnotation-7.0-gd\
//-lvtkRenderingContext2D-7.0-gd\
//-lvtkRenderingContextOpenGL-7.0-gd\
//-lvtkRenderingCore-7.0-gd\
//-lvtkRenderingFreeType-7.0-gd\
//-lvtkRenderingImage-7.0-gd\
//-lvtkRenderingLabel-7.0-gd\
//-lvtkRenderingLOD-7.0-gd\
//-lvtkRenderingOpenGL-7.0-gd\
//-lvtkRenderingQt-7.0-gd\
//-lvtkRenderingVolume-7.0-gd\
//-lvtkRenderingVolumeOpenGL-7.0-gd\
//-lvtksqlite-7.0-gd\
//-lvtksys-7.0-gd\
//-lvtktiff-7.0-gd\
//-lvtkverdict-7.0-gd\
//-lvtkViewsContext2D-7.0-gd\
//-lvtkViewsCore-7.0-gd\
//-lvtkViewsInfovis-7.0-gd\
//-lvtkViewsQt-7.0-gd\
//-lvtkzlib-7.0-gd
//}


//#PCL
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/include/pcl-1.8)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/include/pcl-1.8/pcl)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/Boost/include/boost-1_61)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/Eigen/eigen3)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/FLANN/include)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/FLANN/include/flann)\
//INCLUDEPATH += $$quote(C:\Program Files\OpenNI2/Include)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/Qhull/include)\
//INCLUDEPATH += $$quote(C:\Program Files\PCL1.8.0/3rdParty/VTK/include/vtk-7.0)\



//###########################################################Release
//#else:
//CONFIG(release,debug|release):
//{
//LIBS += -L$$quote(C:\Program Files\PCL1.8.0/lib)\
//#-lpcl_apps_release\
//-lpcl_common_release\
//-lpcl_features_release\
//-lpcl_filters_release\
//-lpcl_io_release\
//-lpcl_io_ply_release\
//-lpcl_kdtree_release\
//-lpcl_keypoints_release\
//-lpcl_ml_release\
//-lpcl_octree_release\
//-lpcl_outofcore_release\
//-lpcl_people_release\
//-lpcl_recognition_release\
//-lpcl_registration_release\
//-lpcl_sample_consensus_release\
//-lpcl_search_release\
//-lpcl_segmentation_release\
//#-lpcl_simulation_release\
//-lpcl_stereo_release\
//-lpcl_surface_release\
//-lpcl_tracking_release\
//-lpcl_visualization_release\

//LIBS += -L$$quote(C:\Program Files\PCL1.8.0/3rdParty/Boost/lib)\
//-llibboost_atomic-vc140-mt-1_61\
//-llibboost_chrono-vc140-mt-1_61\
//-llibboost_container-vc140-mt-1_61\
//-llibboost_context-vc140-mt-1_61\
//-llibboost_coroutine-vc140-mt-1_61\
//-llibboost_date_time-vc140-mt-1_61\
//-llibboost_exception-vc140-mt-1_61\
//-llibboost_filesystem-vc140-mt-1_61\
//-llibboost_graph-vc140-mt-1_61\
//-llibboost_iostreams-vc140-mt-1_61\
//-llibboost_locale-vc140-mt-1_61\
//-llibboost_log-vc140-mt-1_61\
//-llibboost_log_setup-vc140-mt-1_61\
//-llibboost_math_c99-vc140-mt-1_61\
//-llibboost_math_c99f-vc140-mt-1_61\
//-llibboost_math_c99l-vc140-mt-1_61\
//-llibboost_math_tr1-vc140-mt-1_61\
//-llibboost_math_tr1f-vc140-mt-1_61\
//-llibboost_math_tr1l-vc140-mt-1_61\
//-llibboost_mpi-vc140-mt-1_61\
//-llibboost_prg_exec_monitor-vc140-mt-1_61\
//-llibboost_program_options-vc140-mt-1_61\
//-llibboost_random-vc140-mt-1_61\
//-llibboost_regex-vc140-mt-1_61\
//-llibboost_serialization-vc140-mt-1_61\
//-llibboost_signals-vc140-mt-1_61\
//-llibboost_system-vc140-mt-1_61\
//-llibboost_test_exec_monitor-vc140-mt-1_61\
//-llibboost_thread-vc140-mt-1_61\
//-llibboost_timer-vc140-mt-1_61\
//-llibboost_unit_test_framework-vc140-mt-1_61\
//-llibboost_wave-vc140-mt-1_61\
//-llibboost_wserialization-vc140-mt-1_61

//LIBS += -L$$quote(C:\Program Files\PCL1.8.0/3rdParty/FLANN/lib)\
//-lflann\
//-lflann_cpp_s\
//-lflann_s

//LIBS += -L$$quote(C:\Program Files\OpenNI2/Lib)\
//-lOpenNI2

//LIBS += -L$$quote(C:\Program Files\PCL1.8.0/3rdParty/Qhull/lib)\
//-lqhull\
//-lqhullcpp\
//-lqhullstatic\
//-lqhullstatic_r\
//-lqhull_p\
//-lqhull_r

//LIBS += -L$$quote(C:\Program Files\PCL1.8.0\3rdParty\VTK\lib)\
//-lvtkalglib-7.0\
//-lvtkChartsCore-7.0\
//-lvtkCommonColor-7.0\
//-lvtkCommonComputationalGeometry-7.0\
//-lvtkCommonCore-7.0\
//-lvtkCommonDataModel-7.0\
//-lvtkCommonExecutionModel-7.0\
//-lvtkCommonMath-7.0\
//-lvtkCommonMisc-7.0\
//-lvtkCommonSystem-7.0\
//-lvtkCommonTransforms-7.0\
//-lvtkDICOMParser-7.0\
//-lvtkDomainsChemistry-7.0\
//#-lvtkDomainsChemistryOpenGL-7.0\
//-lvtkexoIIc-7.0\
//-lvtkexpat-7.0\
//-lvtkFiltersAMR-7.0\
//-lvtkFiltersCore-7.0\
//-lvtkFiltersExtraction-7.0\
//-lvtkFiltersFlowPaths-7.0\
//-lvtkFiltersGeneral-7.0\
//-lvtkFiltersGeneric-7.0\
//-lvtkFiltersGeometry-7.0\
//-lvtkFiltersHybrid-7.0\
//-lvtkFiltersHyperTree-7.0\
//-lvtkFiltersImaging-7.0\
//-lvtkFiltersModeling-7.0\
//-lvtkFiltersParallel-7.0\
//-lvtkFiltersParallelImaging-7.0\
//-lvtkFiltersProgrammable-7.0\
//-lvtkFiltersSelection-7.0\
//-lvtkFiltersSMP-7.0\
//-lvtkFiltersSources-7.0\
//-lvtkFiltersStatistics-7.0\
//-lvtkFiltersTexture-7.0\
//-lvtkFiltersVerdict-7.0\
//-lvtkfreetype-7.0\
//-lvtkGeovisCore-7.0\
//#-lvtkglew-7.0\
//#-lvtkGUISupportQt-7.0\
//#-lvtkGUISupportQtSQL-7.0\
//-lvtkhdf5-7.0\
//-lvtkhdf5_hl-7.0\
//-lvtkImagingColor-7.0\
//-lvtkImagingCore-7.0\
//-lvtkImagingFourier-7.0\
//-lvtkImagingGeneral-7.0\
//-lvtkImagingHybrid-7.0\
//-lvtkImagingMath-7.0\
//-lvtkImagingMorphological-7.0\
//-lvtkImagingSources-7.0\
//-lvtkImagingStatistics-7.0\
//-lvtkImagingStencil-7.0\
//-lvtkInfovisCore-7.0\
//-lvtkInfovisLayout-7.0\
//-lvtkInteractionImage-7.0\
//-lvtkInteractionStyle-7.0\
//-lvtkInteractionWidgets-7.0\
//-lvtkIOAMR-7.0\
//-lvtkIOCore-7.0\
//-lvtkIOEnSight-7.0\
//-lvtkIOExodus-7.0\
//-lvtkIOExport-7.0\
//-lvtkIOGeometry-7.0\
//-lvtkIOImage-7.0\
//-lvtkIOImport-7.0\
//-lvtkIOInfovis-7.0\
//-lvtkIOLegacy-7.0\
//-lvtkIOLSDyna-7.0\
//-lvtkIOMINC-7.0\
//-lvtkIOMovie-7.0\
//-lvtkIONetCDF-7.0\
//-lvtkIOParallel-7.0\
//-lvtkIOParallelXML-7.0\
//-lvtkIOPLY-7.0\
//-lvtkIOSQL-7.0\
//-lvtkIOVideo-7.0\
//-lvtkIOXML-7.0\
//-lvtkIOXMLParser-7.0\
//-lvtkjpeg-7.0\
//-lvtkjsoncpp-7.0\
//-lvtklibxml2-7.0\
//-lvtkmetaio-7.0\
//-lvtkNetCDF-7.0\
//-lvtkNetCDF_cxx-7.0\
//-lvtkoggtheora-7.0\
//-lvtkParallelCore-7.0\
//-lvtkpng-7.0\
//-lvtkproj4-7.0\
//-lvtkRenderingAnnotation-7.0\
//-lvtkRenderingContext2D-7.0\
//-lvtkRenderingContextOpenGL-7.0\
//-lvtkRenderingCore-7.0\
//-lvtkRenderingFreeType-7.0\
//-lvtkRenderingImage-7.0\
//-lvtkRenderingLabel-7.0\
//-lvtkRenderingLOD-7.0\
//-lvtkRenderingOpenGL-7.0\
//#-lvtkRenderingQt-7.0\
//-lvtkRenderingVolume-7.0\
//-lvtkRenderingVolumeOpenGL-7.0\
//-lvtksqlite-7.0\
//-lvtksys-7.0\
//-lvtktiff-7.0\
//-lvtkverdict-7.0\
//-lvtkViewsContext2D-7.0\
//-lvtkViewsCore-7.0\
//-lvtkViewsInfovis-7.0\
//#-lvtkViewsQt-7.0\
//-lvtkzlib-7.0
//}
