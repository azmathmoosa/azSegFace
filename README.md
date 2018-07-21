# azSegFace
A Semantic Segmentation Network trained to segment Human Faces in potrait photos.

# Details
Framework: Dlib DNN

Network Type: [FCN](https://people.eecs.berkeley.edu/~jonlong/long_shelhamer_fcn.pdf)

Network was first trained on Pascal VOC then retrained on a custom dataset with masked faces in potrait images.  The results are reasonable.
The underlying network is an FCN with 200+ layers.

# Usage

## Build

The project uses CMake.  

### Build in Windows

* Install Cmake, VS 2017 x64 with VC tools v140.  
* Also install CUDA and cuDNN from NVidia's website. This was tested on CUDA v9.0. (If CUDA install fails, disable VS integration ad install again)
* In the repo directory create a new directory called `build` 
* Open a PS terminal, and type `cmake-gui ../`
* In the cmake gui, select VS 2017 x64 as generator. Click configure.
* Cmake will try to configure build environment.  It will print a warning saying `Dlib will not use cuda`
* After configure completes, edit `DLIB_USE_CUDA` and set it to `ON`.  
* Then edit `CUDA_HOST_COMPILER` and set it to `C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/cl.exe`
* Click `configure` again and this time it should complete without errors.
* Click generate and cmake will generate project files.
* Exit `cmake-gui` and in the PS terminal type `cmake --build . --config Release`
* Build might take 15 to 20 minutes depending on your system configuration.

### Build in Linux

* Install cmake, makeutils etc.
* Install Nvidia CUDA and cuDNN
* In the repo directory create a new directory called `build` 
* Open a terminal, and type `cmake-gui ../`
* In the cmake gui, select `Unix Makefiles` as generator. Click configure.
* Cmake will try to configure build environment. 
* Click generate and cmake will generate project files.
* Exit `cmake-gui` and in the terminal type `cmake --build .`
* Build might take 15 to 20 minutes depending on your system configuration.

## Inference

* After build, you can run the application  
```
>cd Release\
>.\dnn_semantic_face_ex.exe \path\to\images\directory

-- or in linux --
$./dnn_semantic_face_ex.exe path/to/images/directory
```
* The application will scan and load the CNN from `..\..\nets\` directory.
* It will show the output for each image in the directory.  Hit enter for next image.

## Training

* Use the VOC annotation tool in `voc_utl` folder to annotate on your custom images.
* The tool will organize the dataset as a directory 

![dataset](https://github.com/azmathmoosa/azSegFace/blob/master/pics/dataset.png)

* To train, use `./dnn_semantic_face_train_ex.exe path/to/dataset/dir`
* The app will first look for `semantic_segmentation_voc2012net.dnn` in the current directory and do transfer learning.
* You may have to edit the src file with the correct path to the net or move the net to the same directory as the training executable.
* After training completes, a new `.dnn` file will be saved that can be used with the inference executable.

# Preview

![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/1.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/2.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/3.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/4.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/5.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/6.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/7.PNG)
![segmentated face](https://github.com/azmathmoosa/azSegFace/blob/master/pics/8.PNG)
