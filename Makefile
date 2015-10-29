CFLAGS = `pkg-config --cflags opencv` `pkg-config gtkmm-3.0 --cflags` `pkg-config gtk+-3.0 --cflags`
INCLUDES = -I/usr/include/eigen3
LIBS = `pkg-config gtkmm-3.0 --libs` `pkg-config gtk+-3.0 --libs` -L/usr/lib -lopencv_calib3d -lopencv_contrib -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_imgproc -lopencv_objdetect -lopencv_highgui -lopencv_gpu -lopencv_superres -lopencv_ocl -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_video -lopencv_videostab -lopencv_photo -lopencv_stitching -lGL -lGLU -lglut -L/usr/local/lib -lpthread -ltbb
% : %.cpp
	g++ -fopenmp $(CFLAGS) $(INCLUDES) -o $@ $< $(LIBS) -std=c++0x

