# Surface Defect Detection: Dataset & Papers

<p>🐎📈 Constantly summarizing open source data sets in the field of surface defect research is very important. 
Important critical papers from year 2017 have been collected and compiled, which can be viewed in the <a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers">:open_file_folder: [<b><i>Papers</i></b>]</a> folder. 🐋 </p>

<p align="center">
  <a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/README.md"><img src="https://img.shields.io/badge/language-English-green" alt="English Version"></a>
  <a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/ReadmeChinese.md"><img src="https://img.shields.io/badge/language-Chinese-red" alt="Chinese Version"></a>
</p>

<div align=center><img src="metal_surface.png"></div>
<br>

## Introduction

<p>At present, surface defect equipment based on machine vision has widely replaced artificial visual inspection in various industrial fields, including 3C, automobiles, home appliances, machinery manufacturing, semiconductors and electronics, chemical, pharmaceutical, aerospace, light industry and other industries. Traditional surface defect detection methods based on machine vision often use conventional image processing algorithms or artificially designed features plus classifiers. Generally speaking, imaging schemes are usually designed by using the different properties of the inspected surface or defects. A reasonable imaging scheme helps to obtain images with uniform illumination and clearly reflect the surface defects of the object. In recent years, many defect detection methods based on deep learning have also been widely used in various industrial scenarios.</p>

<p>Compared with the clear classification, detection and segmentation tasks in computer vision, the requirements for defect detection are very general. In fact, its requirements can be divided into three different levels: "what is the defect" (<strong>classification</strong>), "where is the defect" (<strong>positioning</strong>) And "How many defects are" (<strong>split</strong>).</p>

# Contents

- [Introduction](#introduction)
- [Key Issues](#1-key-issues-in-surface-defect-detection)
  - [Small Sample Problem](#1small-sample-problem)
  - [Real-time Problem](#2real-time-problem)
- [Common Datasets](#2-common-datasets-for-industrial-surface-defect-detection)
  - [Steel Surface: NEU-CLS](#1steel-surface-neu-cls)
  - [Solar Panels: elpv-dataset](#2solar-panels-elpv-dataset)
  - [Metal Surface: KolektorSDD](#3metal-surface-kolektorsdd)
  - [PCB Inspection: DeepPCB](#4pcb-inspection-deeppcb)
  - [Fabric Defects Dataset: AITEX](#5fabric-defects-dataset-aitex)
  - [Fabric Defect Dataset (Tianchi)](#6fabric-defect-dataset-tianchi)
  - [Aluminium Profile Surface Defect Dataset（Tianchi）](#7aluminium-profile-surface-defect-datasettianchi)
  - [Weakly Supervised Learning for Industrial Optical Inspection（DAGM 2007）](#8weakly-supervised-learning-for-industrial-optical-inspectiondagm-2007)
  - [Cracks on the Surface of Construction](#9cracks-on-the-surface-of-the-construction)
  - [Magnetic Tile Dataset](#10magnetic-tile-dataset)
  - [RSDDs: Rail Surface Defect Datasets](#11rsdds-rail-surface-defect-datasets)
  - [Kylberg Texture Dataset v.1.0](#12kylberg-texture-dataset-v10)
- [Papers](#3-surface-defect-detection-papers)
- [Acknowledgements](#acknowledgements)
- [Download](#download)
- [Notification](#notification)
- [Community](#-community)


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

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 2）Real-time Problem

<p>The defect detection methods based on deep learning include three main links in industrial applications: <b>data annotation</b>, <b>model training</b>, and <b>model inference</b>. Real-time in actual industrial applications pays more attention to model inference. At present, most defect detection methods are concentrated in the accuracy of classification or recognition, little attention is paid to the efficiency of model inference. There are many methods for accelerating the model, such as model weighting and model pruning. In addition, although the existing deep learning model uses GPU as a general-purpose computing unit(GPGPU), with the development of technology, it is believed that FPGA will become an attractive alternative.</p>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

## 2. Common Datasets for Industrial Surface Defect Detection

### 1）Steel Surface: NEU-CLS

NEU-CLS can be used for classification and positioning tasks.

- Official Link：http://faculty.neu.edu.cn/yunhyan/NEU_surface_defect_database.html

<div align=center><img src="https://img-blog.csdnimg.cn/20200927223042720.png"></div>

<p>The surface defect dataset released by Northeastern University (NEU) collects six typical surface defects of hot-rolled steel strips, namely rolling scale (RS), plaque (Pa), cracking (Cr), pitting surface (PS), inclusions (In) and scratches (Sc). The dataset includes 1,800 grayscale images, six different types of typical surface defects each of which contains 300 samples. For defect detection tasks, the dataset provides annotations that indicate the category and location of the defect in each image. For each defect, the yellow box is the border indicating its location, and the green label is the category score.</p>

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dSjNOVrR5xByfz4FbNj4tibpHkicPrhs8Ku01sp0Y7qjVFb0h2kaxoZQw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 2）Solar Panels: elpv-dataset

<p>A dataset of functional and defective solar cells extracted from EL images of solar modules.</p>

- link：https://github.com/zae-bayern/elpv-dataset


<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDwNaIgv9VUHeCAeXfauWU8dIY5a7p8M2vrGblgdSaOia5VzQDYIxudcJ9k5k6rANF7MrTjziaJRQoWw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

The dataset contains 2,624 samples of 300x300 pixels 8-bit grayscale images of functional and defective solar cells with varying degree of degradations extracted from 44 different solar modules. The defects in the annotated images are either of intrinsic or extrinsic type and are known to reduce the power efficiency of solar modules.

All images are normalized with respect to size and perspective. Additionally, any distortion induced by the camera lens used to capture the EL images was eliminated prior to solar cell extraction.

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 3）Metal Surface: KolektorSDD

The dataset is constructed from images of defected electrical commutators that were provided and annotated by Kolektor Group d.o.o.. Specifically, microscopic fractions or cracks were observed on the surface of the plastic embedding in electrical commutators. The surface area of each commutator was captured in eight non-overlapping images. The images were captured in a controlled environment.

<div align=center><img src="metal_surface.png"></div>
<br>

- Official Link:https://www.vicos.si/Downloads/KolektorSDD

- Download Link：https://pan.baidu.com/share/init?surl=HSzHC1ltHvt1hSJh_IY4Jg (password：``1zlb``)


The dataset consists of:

- 50 physical items (defected electrical commutators)
- 8 surfaces per item
- Altogether 399 images:<br>
-- 52 images of visible defect<br>
-- 347 images without any defect
- Original images of sizes:<br>
-- width: 500 px<br>
-- height: from 1240 to 1270 px
- For training and evaluation images should be resized to 512 x 1408 px

For each item the defect is only visible in at least one image, while two items have defects on two images, which means there were 52 images where the defects are visible. The remaining 347 images serve as negative examples with non-defective surfaces.

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 4）PCB Inspection: DeepPCB

- Download Link：https://github.com/Charmve/Surface-Defect-Detection/tree/master/DeepPCB

<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/test.jpg" width="375" style="margin:20">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/template.jpg" width="375" style="margin:20"> 
 </div>
<div align=center>
 an example of the tested image 
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 the corresponding template image
 </div>
<p align=center>Figure 1. PCB Inspection Dataset.</p>
<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 5）Fabric Defects Dataset: AITEX

- Download Link：https://pan.baidu.com/s/1cfC4Ll5QlnwN5RTuSZ6b7w (password：``b9uy``)


This dataset consists of 245 4096x256 pixel images with seven different fabric structures. There are 140 non-defect images in the dataset, 20 of each type of fabric. In addition, there are 105 images of different types of fabric defects (12 types) common in the textile industry. The image size allows users to use different window sizes, thereby the number of samples can be increased. The online dataset also contains segmentation masks of all defective images, so that white pixels represent defective areas and the remaining pixels are black.

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Q0FNTB1XHicxJNERSSNPubP0Ga9pfKj8IkvUic7DWHgQBGDXVjJyJWaIDFkCsPPsjODMqmLrh0ZOIdXOm5ibeFz3w/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 6）Fabric Defect Dataset (Tianchi)

- Download Link：https://pan.baidu.com/s/1LMbujxvr5iB3SwjFGYHspA (password：``gat2``)


In the actual production process of cloth, due to the influence of various factors, defects such as stains, holes, lint, etc. will occur. In order to ensure the quality of the product, the cloth needs to be inspected for defects. 

Fabric defect inspection is an important part of the textile industry's production and quality management. At present, manual inspection is susceptible to subjective factors and lacks consistency, and inspection personnel working for a long time under strong light has a great impact on vision. Due to the wide variety of fabric defects, various morphological changes, and the difficulty of observation and recognition, the intelligent detection of fabric defects has been a technical bottleneck that has plagued the industry for many years. 

This dataset covers all kinds of important defects in fabrics in the textile industry, and each picture contains one or more defects. The data includes two types of plain cloth and patterned cloth. Among them, about 8000 pieces of plain cloth data are used for preliminary matches, and about 12,000 pieces of patterned cloth data are used for semi-finals.

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 7）Aluminium Profile Surface Defect Dataset（Tianchi）

- Download Link：https://tianchi.aliyun.com/competition/entrance/231682/information

Due to the influence of various factors in the actual production process of aluminum profile, the surface of the aluminum profile will have cracks, peeling, scratches and other defects, which will seriously affect the quality of the aluminum profile. To ensure product quality, manual visual inspection is required. However, the surface of the aluminum profile itself contains textures, which are not highly distinguishable from defects. 

Traditional manual visual inspection methods have many shortcomings, which are very laborious, cannot accurately judge surface defects in time, and have difficult to control the efficiency of quality inspection. In recent years, deep learning has made rapid progress in image recognition and other fields. Aluminum profile manufacturers are eager to use the latest AI technology to innovate the existing quality inspection process, automatically complete quality inspection tasks, reduce the incidence of missed inspections, and improve product quality. AI technology, especially deep learning, makes aluminum profile product production managers completely free from the inability to fully grasp the state of product surface quality. 

In the dataset of the competition, there are 10,000 pieces of monitoring image data from aluminum profiles with defects in actual production, and each image contains one or more defects. The sample image for machine learning will clearly identify the type of defect contained in the image.


<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Q0FNTB1XHicxJNERSSNPubP0Ga9pfKj8IeudrVjRJ4doibxAtoMqC8LTxZemeZ9SDUzeicSAMrP3yg31MzfD4ygfA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 8）Weakly Supervised Learning for Industrial Optical Inspection（DAGM 2007） 

- Download Link：https://hci.iwr.uni-heidelberg.de/node/3616

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

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 9）Cracks on the Surface of the Construction

CrackForest Dataset is an annotated road crack image database which can reflect urban road surface condition in general.

- Github Link：https://github.com/cuilimeng/CrackForest-dataset 

- Download link：https://pan.baidu.com/s/1108j5QbDr7T3XQvDxAzVpg (password：``jajn``)

<div align=center><img src="https://mmbiz.qpic.cn/mmbiz_png/Z8w2ExrFgDzZJCiczwcBvkghPc7P0sMdkqUbL7Yba9cbGtjKU8JnQZkvsodS5b2xpq1ErehtEMO1ZeO52gm537A/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1"></div>
<br>

<p align=center>Figure 2. Cracks on the Bridge(left) and Cracks on the Road Surface.</p>

- <b>Bridge cracks</b>. There are 2688 images of bridge crack without pixel-level ground truth. From the authors "Liangfu Li, Weifei Ma, Li Li, Xiaoxiao Gao". Files can be reached by visiting https://github.com/Charmve/Surface-Defect-Detection/tree/master/Bridge_Crack_Image.

- <b>Crack on road surface</b>. From Shi Yong, and Cui Limeng and Qi Zhiquan and Meng Fan and Chen Zhensong. Original dataset can be reached at https://github.com/Charmve/Surface-Defect-Detection/tree/master/CrackForest. We extract the image files of the pixel level ground truth.

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 10）Magnetic Tile Dataset

Magnetic tile dataset by githuber: abin24, which can be downloaded from [https://github.com/Charmve/Surface-Defect-Detection/tree/master/Magnetic-Tile-Defect](https://github.com/Charmve/Surface-Defect-Detection/tree/master/Magnetic-Tile-Defect), which was used in their paper "Surface defect saliency of magnetic tile", the paper can be reach by [here](https://link.springer.com/article/10.1007/s00371-018-1588-5) or [here](https://ieeexplore.ieee.org/document/8560423)

![dataset](./Magnetic-Tile-Defect/dataset.jpg) 

<p align=center>Figure 3. An overview of our dataset.</p>

This is also the datasets of the paper "Saliency of magnetic tile surface defects". 
The images of 6 common magnetic tile defects were collected, and their pixel level ground-truth were labeled.

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 11）RSDDs: Rail Surface Defect Datasets

The RSDDs dataset contains two types of datasets: the first is a type I RSDDs dataset captured from the fast lane, which contains 67 challenging images. The second is a Type II RSDDs dataset captured from a normal/heavy transportation track, which contains 128 challenging images.

Each image of the two data sets contains at least one defect, and the background is complex and noisy.

These defects in the RSDDs dataset have been marked by professional human observers in the field of track surface inspection.

<div align=center><img src="rail-dataset.jpg"></div>
<br>

- Official Link：http://icn.bjtu.edu.cn/Visint/resources/RSDDs.aspx

- Download Link：https://pan.baidu.com/share/init?surl=svsnqL0r1kasVDNjppkEwg (password：``nanr``)

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

### 12）Kylberg Texture Dataset v.1.0 

<div align=center><img src="https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X3BuZy9aTmRoV05pYjNJUkJkeklpYVlQQTJ5ZmFXaFRMcVF1UElVdmxPTkVRYURGQzdaT3dWOXBhZWtCckNjQ2FxY0dWb2lhdHk2ZWszRlNTSXhjWVIwelI5TUZIZy82NDA?x-oss-process=image/format,png"></div>
<p align=center>Figure 4. Example patches from each one of the 28 texture classes.</p>

Short description
- 28 texture classes, see Figure 4.
- 160 unique texture patches per class. (Alternative dataset with 12 rotations per each original patch, 160*12=1920 texture patches per class).
- Texture patch size: 576x576 pixels.
- File format: Lossless compressed 8 bit PNG.
- All patches are normalized with a mean value of 127 and a standard deviation of 40.
- One directory per texture class.
- Files are named as follows: ``blanket1-d-p011-r180.png``, where ``blanket1`` is the class name, ``d`` original image sample number (possible values are a, b, c, or d), ``p011`` is patch number 11, ``r180`` patch rotated 180 degrees.

Offical Link: http://www.cb.uu.se/~gustaf/texture/
<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

## 3. Surface Defect Detection Papers

I have collected some articles on surface defect detection. The main objects to be tested are: defects or abnormal objects such as metal surfaces, LCD screens, buildings, and power lines. The methods are mainly classified method, detection method, reconstruction method and generation method. The electronic version (PDF) of the paper is placed under the file named corresponding to the date in the 'Paper' folder.

Go to <a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers">:open_file_folder: [<b><i>Papers</i></b>]</a>.

<br>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

## Acknowledgements

<p>You can see this repo now, we should be grateful to the people who originally open sourced the above data set. They have brought great help to our study and research work. The idea of collecting this data set originally came from reading an article on surface defect detection by SFXiang of "AI算法修炼营(AI_SuanFa)", which prompted me to organize a more comprehensive data set. The collection of papers comes from a CSDNer named "庆志的小徒弟". These papers are only until November 19, and I will continue to be improved after that. <strong>Hopefully, feel free to <a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/CONTRIBUTING.md" target="_blank">CONTRIBUTE</a>.</strong></p>

<p>Finally, I want to thank the open source contributors of the above data set again.</p>

👆 [<b>BACK to Table of Contents</b> -->](#contents)

## Download
- Download ZIP, click [here](https://github.com/Charmve/Surface-Defect-Detection/archive/master.zip)
  <br>or run ```git clone https://github.com/Charmve/Surface-Defect-Detection.git``` in the terminal<br>
- Chinese Mainland：百度网盘下载链接:https://pan.baidu.com/s/122WY8F5VKqm3qMirqebRQw ``提取码:i20n``

👆 [<b>BACK to Table of Contents</b> -->](#contents)

## Notification

This work is originally contributed by lots of great man for their paper work or industry application. <strong>You can only use this dataset for research purpose.</strong>

If you have any questions or idea, please let me know :email: yidazhang1@gmail.com

## 🍮 Community
- Github <a href="https://github.com/Charmve/Surface-Defect-Detection/discussions" target="_blank">discussions 💬</a> or <a href="https://github.com/Charmve/Surface-Defect-Detection/issues" target="_blank">issues 💭</a>

- QQ Group: 734758251 (password：哈哈哈)
- Email: yidazhang1#gmail.com 

## Citation
Use this bibtex to cite this repository:
```
@misc{Surface Defect Detection,
  title={Surface Defect Detection: Dataset and Papers},
  author={Charmve},
  year={2020.09},
  publisher={Github},
  journal={GitHub repository},
  howpublished={\url{https://github.com/Charmve/Surface-Defect-Detection}},
}
```

<br>
* <i>Update on Dec 21，2020 @<a href="https://github.com/Charmve" target="_blank">Charmve</a>, 
    <a class="github-button"
        href="https://github.com/Charmve/Surface-Defect-Detection"
        data-icon="octicon-star" data-show-count="true"
        aria-label="Star Charmve/Surface-Defect-Detection on GitHub">Star</a> 
    and 
    <a class="github-button"
        href="https://github.com/Charmve/Surface-Defect-Detection/fork"
        data-icon="octicon-repo-forked" data-show-count="true"
        aria-label="Fork Charmve/Surface-Defect-Detection on GitHub">Fork</a>
</i>

