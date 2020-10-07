# Surface Defect Detection: dataset & papers

<p>🐎📈 Constantly summarizing open source data sets in the field of surface defect research is very important. 
Important critical papers from year 2017 have been collected and compiled, which can be viewed in the [<b><i>Papers</i></b>](https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers) folder. 🐋 </p>

<p align="center">
  <a href=" "><img src="https://img.shields.io/badge/-English-green" alt="English Version"></a>
  <a href="https://charmve.blog.csdn.net/"><img src="https://img.shields.io/badge/-Chinese-red" alt="Chinese Version"></a>
</p>

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dNvhYK1st5CuJsp4vOzcdj7jnrqy6QV29icM0ugRhHr7UcD04eb4KEIQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

<p>At present, surface defect equipment based on machine vision has widely replaced artificial visual inspection in various industrial fields, including 3C, automobiles, home appliances, machinery manufacturing, semiconductors and electronics, chemical, pharmaceutical, aerospace, light industry and other industries. Traditional surface defect detection methods based on machine vision often use conventional image processing algorithms or artificially designed features plus classifiers. Generally speaking, imaging schemes are usually designed by using the different properties of the inspected surface or defects. A reasonable imaging scheme helps to obtain images with uniform illumination and clearly reflect the surface defects of the object. In recent years, many defect detection methods based on deep learning have also been widely used in various industrial scenarios.</p>

<p>Compared with the clear classification, detection and segmentation tasks in computer vision, the requirements for defect detection are very general. In fact, its requirements can be divided into three different levels: "what is the defect" (<strong>classification</strong>), "where is the defect" (<strong>positioning</strong>) And "How many defects are" (<strong>split</strong>).</p>


## 1. Key Issues in Surface Defect Detection


### 1）Small Sample Problem


<p>The current deep learning methods are widely used in various computer vision tasks, and surface defect detection is generally regarded as its specific application in the industrial field. In traditional understanding, the reason why deep learning methods cannot be directly applied to surface defect detection is because in a real industrial environment, there are too few industrial defect samples that can be provided.</p>


<p>Compared with the more than 14 million sample data in the ImageNet dataset, the most critical problem faced in surface defect detection is <b>small sample problem</b>. In many real industrial scenarios, there are even only a few or dozens of defective images. In fact, for the small sample problem which is one of the key problems in industrial surface defect detection, there are currently 4 different solutions:</p>


<b>- Data Amplification and Generation</b>

<p> The most commonly used defect image expansion method is to use multiple image processing operations such as mirroring, rotation, translation, distortion, filtering, and contrast adjustment on the original defect samples to obtain more samples. Another more common method is data synthesis, where individual defects are often fused and superimposed on normal (non-defective) samples to form defective samples.</p>



<b>- Network Pre-training and Transfer Learning</b>

<p>Generally speaking, using small samples to train deep learning networks can easily lead to <strong>overfitting</strong>, so methods based on pre-training networks or transfer learning are currently one of the most commonly used methods for samples.</p>


<b>- Reasonable Network Structure Design</b>

<p>The need for samples can also be greatly reduced by designing a reasonable network structure. Based on the compressed sampling theorem to compress and expand small sample data, we use CNN to directly classify the compressed sampling data features. Compared with the original image input, compressing the input can greatly reduce the network's demand for samples. In addition, the surface defect detection method based on the twin network can also be regarded as a special network design, which can greatly reduce the sample requirement.</p>


<b>- Unsupervised or Semi-supervised Method</b>

In the unsupervised model, only normal samples are used for training, so there is no need for defective samples. The semi-supervised method can use unlabeled samples to solve the network training problem in the case of small samples.


### 2）Real-time Problem

<p>The defect detection methods based on deep learning include three main links in industrial applications: <b>data annotation</b>, <b>model training</b>, and <b>model inference</b>. Real-time in actual industrial applications pays more attention to model inference. At present, most defect detection methods are concentrated in the accuracy of classification or recognition, little attention is paid to the efficiency of model inference. There are many methods for accelerating the model, such as model weighting and model pruning. In addition, although the existing deep learning model uses GPU as a general-purpose computing unit(GPGPU), with the development of technology, it is believed that FPGA will become an attractive alternative.</p>

## 2. Common Datasets for Industrial Surface Defect Detection

<b>1）Steel Surface: NEU-CLS</b> (can be used for classification and positioning tasks)

Official Link：http://faculty.neu.edu.cn/yunhyan/NEU_surface_defect_database.html

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dV2r2icJmopdRh7QRQyiaibjbUyxdDkBt6vXzL3icyBEYIQHlLBT322D5kg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>

<p>The surface defect dataset released by Northeastern University (NEU) collects six typical surface defects of hot-rolled steel strips, namely rolling scale (RS), plaque (Pa), cracking (Cr), pitting surface (PS), inclusions (In) and scratches (Sc). The dataset includes 1,800 grayscale images, six different types of typical surface defects each of which contains 300 samples. For defect detection tasks, the dataset provides annotations that indicate the category and location of the defect in each image. For each defect, the yellow box is the border indicating its location, and the green label is the category score.</p>

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dSjNOVrR5xByfz4FbNj4tibpHkicPrhs8Ku01sp0Y7qjVFb0h2kaxoZQw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

<b>2）Solar Panels: elpv-dataset</b>

<p>A dataset of functional and defective solar cells extracted from EL images of solar modules.</p>

link：https://github.com/zae-bayern/elpv-dataset


<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dIY5a7p8M2vrGblgdSaOia5VzQDYIxudcJ9k5k6rANF7MrTjziaJRQoWw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>


The dataset contains 2,624 samples of 300x300 pixels 8-bit grayscale images of functional and defective solar cells with varying degree of degradations extracted from 44 different solar modules. The defects in the annotated images are either of intrinsic or extrinsic type and are known to reduce the power efficiency of solar modules.

All images are normalized with respect to size and perspective. Additionally, any distortion induced by the camera lens used to capture the EL images was eliminated prior to solar cell extraction.

<br>

<b>3）Metal Surface：KolektorSDD</b>


The dataset is constructed from images of defected electrical commutators that were provided and annotated by Kolektor Group d.o.o.. Specifically, microscopic fractions or cracks were observed on the surface of the plastic embedding in electrical commutators. The surface area of each commutator was captured in eight non-overlapping images. The images were captured in a controlled environment.

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dNvhYK1st5CuJsp4vOzcdj7jnrqy6QV29icM0ugRhHr7UcD04eb4KEIQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

- Official Link:https://www.vicos.si/Downloads/KolektorSDD

- Wangpan Link：https://pan.baidu.com/share/init?surl=HSzHC1ltHvt1hSJh_IY4Jg (password：``1zlb``)


The dataset consists of:

- 50 physical items (defected electrical commutators)
- 8 surfaces per item
- Altogether 399 images:
-- 52 images of visible defect
-- 347 images without any defect
- Original images of sizes:<br>
-- width: 500 px<br>
-- height: from 1240 to 1270 px
- For training and evaluation images should be resized to 512 x 1408 px

For each item the defect is only visible in at least one image, while two items have defects on two images, which means there were 52 images where the defects are visible. The remaining 347 images serve as negative examples with non-defective surfaces.


<br>

<b>4）PCB Inspection：DeepPCB</b>

Download Link：https://github.com/Charmve/Surface-Defect-Detection/tree/master/DeepPCB

<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/test.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/template.jpg" width="375" style="margin:20"> 
 </div>
<div align=center>
 an example of the tested image 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 the corresponding template image
 </div>

<br>


<b>5）Fabric Defects Dataset: AITEX</b>

Wangpan Link：

https://pan.baidu.com/s/1cfC4Ll5QlnwN5RTuSZ6b7w (password：``b9uy``)


This dataset consists of 245 4096x256 pixel images with seven different fabric structures. There are 140 non-defect images in the dataset, 20 of each type of fabric. In addition, there are 105 images of different types of fabric defects (12 types) common in the textile industry. The image size allows users to use different window sizes, thereby the number of samples can be increased. The online dataset also contains segmentation masks of all defective images, so that white pixels represent defective areas and the remaining pixels are black.

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Q0FNTB1XHicxJNERSSNPubP0Ga9pfKj8IkvUic7DWHgQBGDXVjJyJWaIDFkCsPPsjODMqmLrh0ZOIdXOm5ibeFz3w/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>


<br>

<b>6）Fabric Defect Dataset (Tianchi)</b>

Wangpan Link：

https://pan.baidu.com/s/1LMbujxvr5iB3SwjFGYHspA (password：``gat2``)


In the actual production process of cloth, due to the influence of various factors, defects such as stains, holes, lint, etc. will occur. In order to ensure the quality of the product, the cloth needs to be inspected for defects. 

Fabric defect inspection is an important part of the textile industry's production and quality management. At present, manual inspection is susceptible to subjective factors and lacks consistency, and inspection personnel working for a long time under strong light has a great impact on vision. Due to the wide variety of fabric defects, various morphological changes, and the difficulty of observation and recognition, the intelligent detection of fabric defects has been a technical bottleneck that has plagued the industry for many years. 

This dataset covers all kinds of important defects in fabrics in the textile industry, and each picture contains one or more defects. The data includes two types of plain cloth and patterned cloth. Among them, about 8000 pieces of plain cloth data are used for preliminary matches, and about 12,000 pieces of patterned cloth data are used for semi-finals.


<br>

<b>7）Aluminium Profile Surface Defect Dataset（Tianchi）</b>

Download Link：

https://tianchi.aliyun.com/competition/entrance/231682/information

Due to the influence of various factors in the actual production process of aluminum profile, the surface of the aluminum profile will have cracks, peeling, scratches and other defects, which will seriously affect the quality of the aluminum profile. To ensure product quality, manual visual inspection is required. However, the surface of the aluminum profile itself contains textures, which are not highly distinguishable from defects. 

Traditional manual visual inspection methods have many shortcomings, which are very laborious, cannot accurately judge surface defects in time, and have difficult to control the efficiency of quality inspection. In recent years, deep learning has made rapid progress in image recognition and other fields. Aluminum profile manufacturers are eager to use the latest AI technology to innovate the existing quality inspection process, automatically complete quality inspection tasks, reduce the incidence of missed inspections, and improve product quality. AI technology, especially deep learning, makes aluminum profile product production managers completely free from the inability to fully grasp the state of product surface quality. 

In the dataset of the competition, there are 10,000 pieces of monitoring image data from aluminum profiles with defects in actual production, and each image contains one or more defects. The sample image for machine learning will clearly identify the type of defect contained in the image.


<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Q0FNTB1XHicxJNERSSNPubP0Ga9pfKj8IeudrVjRJ4doibxAtoMqC8LTxZemeZ9SDUzeicSAMrP3yg31MzfD4ygfA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

<b>8）Weakly Supervised Learning for Industrial Optical Inspection（DAGM 2007）</b> 

Download Link：

https://hci.iwr.uni-heidelberg.de/node/3616

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDzZJCiczwcBvkghPc7P0sMdkIcMQ8rKaEwhRKhYLnU00KuhweMiaS1Q32ZPGplzYPxyXcicH4zDPFyhQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>

<br>

Dataset introduction:

- Mainly aimed at miscellaneous defects on textured backgrounds.

- Training data with weaker supervision.

- Contains ten data sets, the first six are training data sets, and the last four are test data sets.

- Each dataset contains 1000 "non-defective" images and 150 "defective" images saved in grayscale 8-bit PNG format. Each data set is generated by a different texture model and defect model.

- The background texture of the "No Defect" image shows no defect, and the background texture of the "No Defect" image has exactly one marked defect.

- All datasets have been randomly divided into training and testing sub-data sets of equal size.

- Weak labels are represented by ellipses, which roughly indicate the defect area.         

<br>

<b>9）Cracks on the Surface of the Construction</b> 

CrackForest Dataset is an annotated road crack image database which can reflect urban road surface condition in general.

- Github Link：https://github.com/cuilimeng/CrackForest-dataset 

- Download link：https://pan.baidu.com/s/1108j5QbDr7T3XQvDxAzVpg (password：``jajn``)



<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDzZJCiczwcBvkghPc7P0sMdkqUbL7Yba9cbGtjKU8JnQZkvsodS5b2xpq1ErehtEMO1ZeO52gm537A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

<b> Cracks on the Bridge(left) and Cracks on the Road Surface</b>

- Bridge cracks. There are 2688 images of bridge crack without pixel-level ground truth. From the authors "Liangfu Li Weifei Ma Li Li Xiaoxiao Gao". Files can be reached by visiting https://github.com/Charmve/Surface-Defect-Detection/tree/master/Bridge_Crack_Image.

- Crack on road surface. From Shi, Yong, and Cui, Limeng and Qi, Zhiquan and Meng, Fan and Chen, Zhensong. Original dataset can be reached at https://github.com/Charmve/Surface-Defect-Detection/tree/master/CrackForest. We extract the image files of the pixel level ground truth.

<br>
<b>10）Magnetic Tile Dataset </b>

Magnetic tile dataset by githuber: abin24, which can be downloaded from [https://github.com/Charmve/Surface-Defect-Detection/tree/master/Magnetic-Tile-Defect](https://github.com/Charmve/Surface-Defect-Detection/tree/master/Magnetic-Tile-Defect), which was used in their paper "Surface defect saliency of magnetic tile", the paper can be reach by [here](https://link.springer.com/article/10.1007/s00371-018-1588-5) or [here](https://ieeexplore.ieee.org/document/8560423)

![dataset](./Magnetic-Tile-Defect/dataset.jpg) 

<p align=center>Figure 1. An overview of our dataset.</p>

This is also the datasets of the paper "Saliency of magnetic tile surface defects". 
The images of 6 common magnetic tile defects were collected, and their pixel level ground-truth were labeled.


<b>11）RSDDs: Rail Surface Defect Datasets</b> 

The RSDDs dataset contains two types of datasets: the first is a type I RSDDs dataset captured from the fast lane, which contains 67 challenging images. The second is a Type II RSDDs dataset captured from a normal/heavy transportation track, which contains 128 challenging images.

Each image of the two data sets contains at least one defect, and the background is complex and noisy.

These defects in the RSDDs dataset have been marked by professional human observers in the field of track surface inspection.

<div align=center><img src="rail-dataset.jpg"></div>
<br>

Official Link：http://icn.bjtu.edu.cn/Visint/resources/RSDDs.aspx

Download Link：https://pan.baidu.com/share/init?surl=svsnqL0r1kasVDNjppkEwg (password：``nanr``)


<br>

<b>12）Kylberg Texture Dataset v.1.0 </b> 

<div align=center><img src="http://www.cb.uu.se/~gustaf/texture/fig_sample.png"></div>
<p align=center>Figure 2. Example patches from each one of the 28 texture classes.</p>

Short description
- 28 texture classes, see Figure 2.
- 160 unique texture patches per class. (Alternative dataset with 12 rotations per each original patch, 160*12=1920 texture patches per class).
- Texture patch size: 576x576 pixels.
- File format: Lossless compressed 8 bit PNG.
- All patches are normalized with a mean value of 127 and a standard deviation of 40.
- One directory per texture class.
- Files are named as follows: blanket1-d-p011-r180.png, where blanket1 is the class name, d original image sample number (possible values are a, b, c, or d), p011 is patch number 11, r180 patch rotated 180 degrees.

Offical Link:http://www.cb.uu.se/~gustaf/texture/


<br>

## 3. Surface Defect Detection Papers

I have collected some articles on surface defect detection. The main objects to be tested are: defects or abnormal objects such as metal surfaces, LCD screens, buildings, and power lines. The methods are mainly classified method, detection method, reconstruction method and generation method. The electronic version (PDF) of the paper is placed under the file named corresponding to the date in the 'Paper' folder.

Go to [Papers](https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers).

<br>
* <i>Update by Sep 27，2020 @<a href="https://github.com/Charmve" target="_blank">Charmve</a>, follow me</i>
