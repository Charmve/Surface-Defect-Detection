# DeepPCB
DeepPCB: a dataset contains 1,500 image pairs, each of which consists of a defect-free template image and an aligned tested image with annotations including positions of 6 most common types of PCB defects: open, short, mousebite, spur, pin hole and spurious copper.

## Dataset Description
### Image Collection
All the images in this dataset are obtained from a linear scan CCD in resolution around 48 pixels per 1 millimetre. The defect-free template images are manually checked and cleaned from sampled images in the above manner. The original size of the template and tested image is around 16k x 16k pixels. Then they are cropped into many sub-images with size of 640 x 640 and aligned through template matching techniques. Next, a threshold is carefully selected to employ binarization to avoid illumination disturbance. Notice that pre-processing algorithms can be various according to the specific PCB defect detection algorithms, however, the image registration and thresholding techniques are common process for high-accuracy PCB defect localization and classification. An example pair in DeepPCB dataset is illustrated in the following figure, where the right one is the defect-free template image and the left one is the defective tested image with the ground truth annotations.
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/test.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/template.jpg" width="375" style="margin:20"> 
 </div>
<div align=center>
 an example of the tested image 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 the corresponding template image
 </div>

### Image Annotation
We use the axis-aligned bounding box with a class ID for each defect in the tested images. As illustrated in the above, we annotate six common types of PCB defects: open, short, mousebite, spur, pin hole and spurious copper. Since there is only a few defects in the real tested image, we manually argument some artificial defects on each tested image according to the PCB defect patterns, which leads to around 3 to 12 defects in each 640 x 640 image. The number of PCB defects is shown in the following figure. We separate 1,000 images as training set and the remains as test set.

Each annotated image owns an annotation file with the same filename, e.g.**_00041000_test.jpg_**, **_00041000_temp.jpg_** and **_00041000.txt_** are the tested image, template image and the corresponding annotation file. Each defect on the tested image are annotated as the format:**_x1,y1,x2,y2,type_** , where **_(x1,y1)_** and **_(x2,y2)_** is the top left and the bottom right corner of the bounding box of the defect. **_type_** is an integer ID that follows the matches: **0-background (not used), _1-open, 2-short, 3-mousebite, 4-spur, 5-copper, 6-pin-hole_**.
<div align=center>
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/CountPCB.png" width="560"> 
 </div>

 The annotation tool is now available with the source code in the **_./tools_** directory.
 
### Benchmarks
The average precision rate and F-score are used for evaluation. A detection is correct only if the intersection of unit (IoU) between the detected bounding box and any of the ground truth box with the same class is larger than 0.33. F-score is calculated as: F-score=2PR/(P+R), where P and R is the precision and recall rate. Notice that F-score is threshold-sensitive, which means you could adjust your score threshold to obtain a better result. Although F-score is not as fair as the mAP criteria but more practical since a threshold should always be given when deploying the model and not all of the algorithms have a score evaluation for the target. Thus, F-score and mAP are both under consideration in the benchmarks. 

The evaluation script for mAP and F-score are borrowed from [Icdar2015 evaluation scripts](http://rrc.cvc.uab.es/?ch=4&com=mymethods&task=1) with small modification (You may first register an account.). Here, we give the modified evaluation scripts and the ground truth _gt.zip_ file of the test set in _evaluation/_ directory. You can evaluate your own method by following instructions:
* run your algorithm and save the detect result for each image named as *image_name.txt*, where the *image_name* should be exactly the same as in the *gt.zip*. You should follow the format of *evaluation/gt.zip* except that the output description of each defect from your algorithm should be: **_x1,y1,x2,y2,confidence,type_** , where **_(x1,y1)_** and **_(x2,y2)_** is the top left and the bottom right corner of the bounding box of the defect. **_confidence_** is a float number to show how confident you believe such detection result. **_type_** is a string and should be one of the following: **_open,short,mousebite,spur,copper,pin-hole_**. **Notice there is no space except the comma**.
* zip your **_.txt_** file to **_res.zip_**. (You should not contain any sub-directory in the **_res.zip_** file)
* run the evaluation script: *python script.py -s=res.zip -g=gt.zip*


## Approach
This section with the source code will be public after the acceptance of the paper.

### Experiment results
Here we show some results of our model based on deep neural network. Our model achieves **_98.6% mAp, 98.2% F-score @ 62FPS_**. More statistic analysis will be public after the acceptance of the paper. The green bounding box is the predicted location of the PCB defect with the confidence on the top of each.

Result pair 1:
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_test1.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_temp1.jpg" width="375" style="margin:20"> 
 </div>
Result pair 2:
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_test2.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_temp2.jpg" width="375" style="margin:20"> 
 </div>
 Result pair 3:
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_test3.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_temp3.jpg" width="375" style="margin:20"> 
 </div>
 Result pair 4:
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_test4.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/result/result_temp4.jpg" width="375" style="margin:20"> 
 </div>

#### Notification
This work is contributed by the paper **_On-line PCB Defect Detector On A New PCB Defect Dataset_**. You can only use this dataset for research purpose.
