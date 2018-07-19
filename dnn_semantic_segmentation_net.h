// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*
    This example shows how to do semantic segmentation on an image using net pretrained
    on the PASCAL VOC2012 dataset.  For an introduction to what segmentation is, see the
    accompanying header file dnn_semantic_segmentation_ex.h.

    Instructions how to run the example:
    1. Download the PASCAL VOC2012 data, and untar it somewhere.
       http://host.robots.ox.ac.uk/pascal/VOC/voc2012/VOCtrainval_11-May-2012.tar
    2. Build the dnn_semantic_segmentation_train_ex example program.
    3. Run:
       ./dnn_semantic_segmentation_train_ex /path/to/VOC2012
    4. Wait while the network is being trained.
    5. Build the dnn_semantic_segmentation_ex example program.
    6. Run:
       ./dnn_semantic_segmentation_ex /path/to/VOC2012-or-other-images

    An alternative to steps 2-4 above is to download a pre-trained network
    from here: http://dlib.net/files/semantic_segmentation_voc2012net.dnn

    It would be a good idea to become familiar with dlib's DNN tooling before reading this
    example.  So you should read dnn_introduction_ex.cpp and dnn_introduction2_ex.cpp
    before reading this example program.
*/


#include <iostream>
#include <dlib/data_io.h>
#include <dlib/gui_widgets.h>
#include <dlib/matrix.h>

using namespace std;
using namespace dlib;


void load_net(string path);
matrix<uint16_t> infer_net(dlib::matrix<rgb_pixel> input_image);
