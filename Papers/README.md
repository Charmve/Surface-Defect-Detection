<div id="outputFigDisplay" class="fig">
    <pre id="taag_output_text" style="float:left;" class="flag" contenteditable="true">
    ____  _                                        
  / ___|| |__    __ _  _ __  _ __ ___ __   __ ___ 
 | |    | '_ \  / _` || '__|| '_ ` _ \\ \ / // _ \
 | |___ | | | || (_| || |   | | | | | |\ V /|  __/
  \____||_| |_| \__,_||_|   |_| |_| |_| \_/  \___|   
    </pre>
</div>

<p align="center">
  <a href="https://charmve.blog.csdn.net/"><img src="https://img.shields.io/badge/blog-Charmve-blue" alt="css"></a>
  <a href="https://charmve.blog.csdn.net/"><img src="https://www.geekxh.com/trending.svg?label=html" alt="html"></a>
  <a href="https://github.com/haizlin/fe-interview/stargazers"><img src="https://img.shields.io/github/stars/geekxh/hello-algorithm.svg" alt="Statr"></a>
</p>

# -Surface Defect Detection Papers-
🐎📈 collecting Surface-Defect-Detection paper and dataset 🐋


分享一些表面缺陷检测的文章，主要检测对象是：金属表面、LCD屏、建筑、输电线等缺陷或异常检物。方法以分类方法、检测方法、重构方法、生成方法为主。电子版论文放在了paper文件的对应日期文件下。

## 2019.01

### [1]CNN做分类

论文题目：A fast and robust convolutional neural network-based defect detection model in product quality control  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/A%20fast%20and%20robust%20convolutional%20neural%20network-based%20defect%20detection%20model%20in%20product%20quality%20control.pdf" target="_blank">paper</a>]

摘要：The fast and robust automated quality visual inspection has received increasing attention in the product quality control for production efficiency. To effectively detect defects in products, many methods focus on the handcrafted optical features. However, these methods tend to only work well under specified conditions and have many requirements for the input. So the work in this paper targets on building a deep model to solve this problem. The elaborately designed deep convolutional neural networks (CNN) proposed by us can automatically extract powerful features with less prior knowledge about the images for defect detection, while at the same time is robust to noise. We experimentally evaluate this CNN model on a benchmark dataset and achieve a fast detection result with a high accuracy, surpassing the state-of-the-art methods. 

个人总结：2017年7月的一篇杂志文章。作者使用一个多层的CNN网络对DAGM2007数据集中的六类缺陷样本进行分类，分类结束之后，对于每一类样本进行缺陷检测。具体做法是：1.使用sliding-window方法在512×512的原图上进行采样，采样大小为128×128；2.对上部分每一类图像采样后的小图像块进行二分类（有缺陷和无缺陷）。最终实验和以前传统方法做的对比，比如SIFT+SVM，效果不错。下图为文章两次分类使用的CNN网络，两次分类的区别在于：1.全连接层的输入分别为6和2；2.输入的图像尺寸不同。

### [2]图像金字塔层次结构思想和卷积去噪自编码器网络对纹理缺陷做检测

论文题目：An Unsupervised-Learning-Based Approach for Automated Defect Inspection on Textured Surfaces [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/An%20Unsupervised-Learning-Based%20Approach%20for%20Automated%20Defect%20Inspection%20on%20Textured%20Surfaces.pdf" target="_blank">paper</a>]

摘要：Automated defect inspection has long been a challenging task especially in industrial applications, where collecting and labeling large amounts of defective samples are usually harsh and impracticable. In this paper, we propose an approach to detect and localize defects with only defect-free samples for model

training. This approach is carried out by reconstructing image patches with convolutional denoising autoencoder networks at different Gaussian pyramid levels, and synthesizing detection results from these different resolution channels. Reconstruction residuals of the training patches are used as the indicator for
direct pixelwise defect prediction, and the reconstruction residual map generated in each channel is combined to generate the final inspection result. This novel method has two prominent characteristics, which benefit the implementation of automatic defect inspection in practice. First, it is absolutely unsupervised that no human intervention is needed throughout the inspection process. Second, multimodal strategy is utilized in this method to synthesize results from multiple pyramid levels. This strategy is capable of improving the robustness and accuracy of the method. To evaluate this approach, experiments on convergence, noise immunity, and defect inspection accuracy are conducted. Furthermore, comparative tests with some excellent algorithms on actual and simulated data sets are performed. Experimental results demonstrated the effectiveness and superiority of the proposed method on homogeneous and nonregular textured surfaces. 

个人总结：2018年6月的一篇杂志文章。文章和4月在另一篇杂志上的《Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model》一文核心内容上基本一样，作者是同一人。主要框架：结合图像金字塔层次结构思想和卷积去噪自编码器网络（CDAE）对纹理图像缺陷进行检测。具体实施：利用不同高斯金字塔层次的卷积去噪自编码器网络重构image patchs，利用训练patch的重构残差作为直接像素方向缺陷预测的指标，将每个通道生成的重构残差图结合起来，生成最终的检测结果。  论文是无监督的方法做缺陷检测，在布匹丝织物这种重复性背景纹理很强的图集上效果很好，在金属表面、加工部件表面数据集效果一般，甚至很差。在最后的实验部分，作者也是用了DAGM2007数据集做了测试，效果一般，远远达不到工业应用要求，但相对其他方法，部分种类效果有提升。

### [3]级联自编码器(CASAE)结构用于金属表面异常的分割和定位

论文题目：Automatic Metallic Surface Defect Detection and Recognition with Convolutional Neural Networks [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/Automatic_Metallic_Surface_Defect_Detection_and_Re.pdf" target="_blank">paper</a>]

摘要：Automatic metallic surface defect inspection has received increased attention in relation
to the quality control of industrial products. Metallic defect detection is usually performed against
complex industrial scenarios, presenting an interesting but challenging problem. Traditional methods
are based on image processing or shallow machine learning techniques, but these can only detect
defects under specific detection conditions, such as obvious defect contours with strong contrast
and low noise, at certain scales, or under specific illumination conditions. This paper discusses the
automatic detection of metallic defects with a twofold procedure that accurately localizes and classifies
defects appearing in input images captured from real industrial environments. A novel cascaded
autoencoder (CASAE) architecture is designed for segmenting and localizing defects. The cascading
network transforms the input defect image into a pixel-wise prediction mask based on semantic
segmentation. The defect regions of segmented results are classified into their specific classes via
a compact convolutional neural network (CNN). Metallic defects under various conditions can be
successfully detected using an industrial dataset. The experimental results demonstrate that this
method meets the robustness and accuracy requirements for metallic defect detection. Meanwhile,
it can also be extended to other detection applications. 

个人总结：2018年九月一篇杂志文章。作者提出来一种用于金属表面缺陷的检测方法，借助自编码器在图像重建上的性能，设计一种级联自编码器(CASAE)体系结构，用于金属表面异常的分割和定位。再利用CNN将分割后的缺陷区域做细分类。具体的pipeline如下，整体来说文章的思路就是语义粗略分割+卷积细分类。详细的分析可以看：https://blog.csdn.net/qq_27871973/article/details/83817694

### [4]Faster R-CNN用于土木行业缺陷检测

论文题目：Autonomous Structural Visual Inspection Using Region-Based Deep Learning for Detecting Multiple Damage Types [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/Autonomous%20Structural%20Visual%20Inspection%20Using%20Region-Based%20Deep%20Learning%20for%20Detecting%20Multiple%20Damage%20Types.pdf" target="_blank">paper</a>]

摘要： Computer vision-based techniques were developed to overcome the limitations of visual inspection by trained human resources and to detect structural damage in images remotely, but most methods detect only specific types of damage, such as concrete or steel cracks. To provide quasi real-time simultaneous detection of multiple types of damages, a Faster Region-based Convolutional Neural Network (Faster R-CNN)-based structural visual inspection method is proposed. To realize this, a database including 2,366 images (with 500 × 375 pixels) labeled for five types of damages—concrete crack, steel corrosion with two levels (medium and high), bolt corrosion, and steel delamination—is developed. Then, the architecture of the Faster R-CNN is modified, trained, validated, and tested using this database. Results show 90.6%, 83.4%, 82.1%, 98.1%, and 84.7% average precision (AP) ratings for the five damage types, respectively, with a mean AP of 87.8%. The robustness of the trained Faster R-CNN is evaluated and demonstrated using 11 new 6,000 × 4,000-pixel images taken of different structures. Its performance is also compared to that of the traditional CNN-based method. Considering that the proposed method provides a remarkably fast test speed (0.03 seconds per image with 500 × 375 resolution), a framework for quasi real-time damage detection on video using the trained networks is developed. 

个人总结：2018年的一篇杂志文章。文章使用Faster R-CNN用于土木建筑领域的混凝土。钢裂纹等损伤检测，文章主要是把Faster R-CNN迁移到行业检测，算是Faster R-CNN模型的实战。

## 2019.02

### [1]主动学习用于缺陷分类

论文题目：Deep Active Learning for Civil Infrastructure Defect Detection and Classification [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Deep%20Active%20Learning%20for%20Civil%20Infrastructure%20Defect%20detection%20and%20clssification.pdf" target="_blank">paper</a>]

论文摘要：Automatic detection and classification of defects in infrastructure surface images can largely
boost its maintenance efficiency. Given enough labeled images, various supervised learning
methods have been investigated for this task, including decision trees and support vector
machines in previous studies, and deep neural networks more recently. However, in real world
applications, labels are harder to obtain than images, due to the limited labeling resources
(i.e., experts). Thus we propose a deep active learning system to maximize the performance.
A deep residual network is firstly designed for defect detection and classification in an image.
Following our active learning strategy, this network is trained as soon as an initial batch of
labeled images becomes available. It is then used to select a most informative subset of new
images and query labels from experts to retrain the network. Experiments demonstrate more
efficient performance improvements of our method than baselines, achieving 87.5% detection
accuracy. 

个人总结：主动学习思想结合ResNet网络对行业缺陷样本进行分类，提升准确率。

### [2]CNN的一个实验在LCD屏异常检测

论文题目：Defect Detection of Mobile Phone Surface Based on Convolution Neural Network  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Defect%20Detection%20of%20Mobile%20Phone%20Surface%20based%20on%20convlution%20nerual%20networks.pdf" target="_blank">paper</a>]

论文摘要：Automatic surface defect detection of mobile phone in large scale needs to
process high resolution images and handle various defects while achieving high
accuracy rate. This study proposes a defect detection method based on convolution
neural network (CNN). Firstly, the original surface image of mobile phone is
obtained using industrial linear array camera. Secondly, the obtained images are
automatically segmented into specified sizes by the proposed preprocessing step.
Moreover, we design the CNN on basis of GoogLeNet network, which greatly
reduces the number of parameters without compromising prediction rate. At last the
designed CNN are trained and tested. The trained CNN can be combined with a
sliding window technique to detect any ROI with size larger than 256×256
resolutions in the original images. The experimental results show that the defect
detection rate of the designed CNN can achieve as high as 99.5%. 

### [3] 深度学习&迁移学习

论文题目：Defects Detection Based on Deep Learning and Transfer Learning  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Defects%20Detection%20Based%20on%20Deep%20Learning%20and%20Transfer%20Learning.pdf" target="_blank">paper</a>]

论文摘要：Defect detection is an important step in the feld of industrial production. Through the study of deep
learning and transfer learning, this paper proposes a method of defect detection based on deep learning
and transfer learning. Our method frstly establishes Deep Belief Networks and trains it according to
the source domain sample feature, in order to obtain the weights of the network according to source
domain samples. Then, the structure and parameters of the source domain DBN is transferred to the
target domain and target domain samples are used to fne-tune the network parameters to get the
mapping relationship between the target domain training sample and defect-free template. Finally, the
defects of testing samples will be detected by compared with the reconstruction image. This method
not only can make full use of the advantages of DBN, also can solve over-ftting in DBN network
training through parameters transfer learning. These experiments show that DBN is a successful
approach in the high-dimensional-feature-space information extraction task, which can perfectly
establishes the mapping relationship, and can quickly detect defects with a high accuracy. 

## 2019.03

### [1]分割网络用于磁瓦缺陷检测

论文题目：Surface Defect Saliency of Magnetic Tile  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

论文摘要：Vision-based detection on surface defects has long postulated in the magnetic tile automation process. In this work, we introduce a real-time and multi-module neural network model called MCuePush U-Net, specifically designed for the image saliency detection of magnetic tile. We show that the model exceeds the state-of-the-art, in which it both effectively and explicitly maps multiple surface defects from low-contrast images. Our model significantly reduces time cost of machinery from 0.5s per image to 0.07s, and enhances saliency accuracy on surface defect detection. 

### [2]经典的PHOT算法

论文题目：The Phase Only Transform for unsupervised surface defect detection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

论文摘要：We present a simple, fast, and effective method to detect defects on textured surfaces. Our method is unsupervised and contains no learning stage or information on the texture being inspected. The new method is based on the Phase Only Transform (PHOT) which correspond to the Discrete Fourier Transform (DFT), normalized by the magnitude. The PHOT removes any regularities, at arbitrary
scales, from the image while preserving only irregular patterns considered to represent defects. The localization is obtained by the inverse transform followed by adaptive thresholding using a simple standard statistical method. The main computational requirement is thus to apply the DFT on the input image. The new method is also easy to implement in a few lines of code. Despite its simplicity, the methods is
shown to be effective and generic as tested on various inputs, requiring only one parameter for sensitivity. We provide theoretical justification based on a simple model and show results on various kinds of patterns. We also discuss some limitations. 

### [3]经典的DCT算

论文题目：Tiny surface defect inspection of electronic passive components using discrete cosine transform decomposition and cumulative sum techniques [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

论文摘要：Passive components, owing to their low or no power consumption, are widely used in modern electronic devices. Nevertheless, tiny defects that often appear in the surface of passive components impair not only their appearances but also their functions. This paper proposes a global approach for the automated visual inspection of tiny surface defects in SBL (Surface Barrier Layer) chips, whose random surface texture contains no repetitions of basic texture primitives. The proposed method, taking advantage of the DCT decomposition and the cumulative sum techniques, does not requires textural features, the lack of which often limits the application of feature extraction-based methods. We apply the cumulative sum algorithm to the odd–odd matrix that gathers most power spectra in the decomposed DCT frequency domain, and select the large-magnitude frequency values that represent the background texture of the surface. Then, by reconstructing the frequency matrix without the selected frequency values, we eliminate random texture patterns and retain anomalies in the restored image. Experimental results demonstrate the effectiveness of the proposed method in inspecting tiny defects in random textures. 

## 2019.04

### [1]一种无监督的纳米纤维材料扫描电镜图像（SEM）异常检测方法

论文题目：Anomaly Detection in Nanofibrous Materials by CNN-Based Self-Similarity [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

论文摘要：Automatic detection and localization of anomalies in nanofibrous materials help to reduce
the cost of the production process and the time of the post-production visual inspection process.
Amongst all the monitoring methods, those exploiting Scanning Electron Microscope (SEM) imaging
are the most effective. In this paper, we propose a region-based method for the detection and
localization of anomalies in SEM images, based on Convolutional Neural Networks (CNNs) and
self-similarity. The method evaluates the degree of abnormality of each subregion of an image
under consideration by computing a CNN-based visual similarity with respect to a dictionary of
anomaly-free subregions belonging to a training set. The proposed method outperforms the state
of the art. 

个人总结：详细的分析见：https://blog.csdn.net/qq_27871973/article/details/86007150

### [2]Faster R-CNN用于土木建筑领域的混凝土

论文题目：Automatic Defect Detection of Fasteners on theCatenary Support Device Using Deep
Convolutional Neural Network  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

摘要：The excitation and vibration triggered by the longterm operation of railway vehicles inevitably result in defective states of catenary support devices. With the massive construction of high-speed electrified railways, automatic defect detection of diverse and plentiful fasteners on the catenary support device
is of great significance for operation safety and cost reduction. Nowadays, the catenary support devices are periodically captured by the cameras mounted on the inspection vehicles during the night, but the inspection still mostly relies on human visual interpretation. To reduce the human involvement, this paper
proposes a novel vision-based method that applies the deep convolutional neural networks (DCNNs) in the defect detection of the fasteners. Our system cascades three DCNN-based detection stages in a coarse-to-fine manner, including two detectors to sequentially localize the cantilever joints and their fasteners and a
classifier to diagnose the fasteners’ defects. Extensive experiments and comparisons of the defect detection of catenary support devices along the Wuhan–Guangzhou high-speed railway line indicate that the system can achieve a high detection rate with good adaptation and robustness in complex environments. 

个人总结：2018年2月的一篇杂志论文。作者将深度卷积神经网络(DCNNs)应用到高铁线路紧固件缺陷检测。结合SSD、YOLO等网络方法构建了一个从粗到细的级联检测网络，包括：两个检测器对悬臂节点及其紧固件进行定位，一个分类器对紧固件缺陷进行分类。特别是实验部分，作者做的很充分。

### [3] 多尺度卷积去噪自动编码器网络模型

论文题目：Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

摘要：Fabric defect detection is a necessary and essential step of quality control in the textile
manufacturing industry. Traditional fabric inspections are usually performed by manual visual
methods, which are low in efficiency and poor in precision for long-term industrial applications.
In this paper, we propose an unsupervised learning-based automated approach to detect and localize
fabric defects without any manual intervention. This approach is used to reconstruct image patches
with a convolutional denoising autoencoder network at multiple Gaussian pyramid levels and to
synthesize detection results from the corresponding resolution channels. The reconstruction residual
of each image patch is used as the indicator for direct pixel-wise prediction. By segmenting and
synthesizing the reconstruction residual map at each resolution level, the final inspection result can
be generated. This newly developed method has several prominent advantages for fabric defect
detection. First, it can be trained with only a small amount of defect-free samples. This is especially
important for situations in which collecting large amounts of defective samples is difficult and
impracticable. Second, owing to the multi-modal integration strategy, it is relatively more robust
and accurate compared to general inspection methods (the results at each resolution level can be
viewed as a modality). Third, according to our results, it can address multiple types of textile fabrics,
from simple to more complex. Experimental results demonstrate that the proposed model is robust
and yields good overall performance with high precision and acceptable recall rates. 

个人总结：核心思路同2019.01的第二篇。

## 2019.05

### [1]CNN做分类

论文题目：Design of deep convolutional neural network architectures for automated feature extraction in industrial inspection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

论文摘要：Fast and reliable industrial inspection is a main challenge in manufacturing scenarios. However, the defect
detection performance is heavily dependent on manually defined features for defect representation. In
this contribution, we investigate a new paradigm from machine learning, namely deep machine learning
by examining design configurations of deep Convolutional Neural Networks (CNN) and the impact of
different hyper-parameter settings towards the accuracy of defect detection results. In contrast to
manually designed image processing solutions, deep CNN automatically generate powerful features by
hierarchical learning strategies from massive amounts of training data with a minimum of human
interaction or expert process knowledge. An application of the proposed method demonstrates excellent
defect detection results with low false alarm rates. 

### [2] 威布尔Weibull

论文题目：Non-parametric texture defect detection using Weibull features [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

论文摘要：The detection of abnormalities is a very challenging problem in computer vision, especially if these abnormalities must be detected in images of textured surfaces such as textile, stone, or wood. We propose a novel, nonparametric approach for defect detection in textures that only employs two features. We compute the two parameters of a Weibull fit for the distribution of image gradients in local regions. Then, we perform a simple novelty detection algorithm in order to detect arbitrary deviations of the reference texture. Therefore, we evaluate the Euclidean distances of all local patches to a reference point in the Weibull space, where the reference point is determined for each texture image individually. Thus, our approach becomes independent of the particular texture type and also independent of a certain defect type.
For performance evaluation we use the highly challenging database provided by Bosch for a contest on
industrial optical inspection with different classes of textures and different defect types. By using the Weibull parameters we can detect local deviations of texture images in an unsupervised manner with high accuracy. Compared to existing approaches such as Gabor filters or grey level statistics, our approach is not only powerful, but also very efficient such that it can also be applied for real-time applications. 

### [3]神经进化Neuro-Evolution

论文题目：Learning Defect Classifiers for Visual Inspection Images by Neuro-Evolution using Weakly Labelled Training Data  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

论文摘要： This article presents results from experiments where a detector for defects in visual inspection images was learned from scratch by EANT2, a method for evolutionary reinforcement learning. The detector is constructed as a neural network that takes as input statistical data on filter responses
from a bank of image filters applied to an image region. Training is done on example images with weakly labelled defects. Experiments show good results of EANT2 in an application area where evolutionary methods are rare. 

## 2019.06

### [1]GAN用于缺陷检测

论文题目：A Surface Defect Detection Method Based on Positive Samples  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

论文摘要：Surface defect detection and classification based on machine vision can greatly improve the efficiency of industrial production. With enough labeled images, defect detection methods based on convolution neural network have achieved the detection effect of state-of-art. However in practical applications, the defect samples or negative samples are usually difficult to be collected before‐
hand and manual labelling is time-consuming. In this paper, a novel defect detection framework only based on training of positive samples is proposed. The basic detection concept is to establish a reconstruction network which can repair defect areas in the samples if they are existed, and then make a comparison between the input sample and the restored one to indicate the accurate defect areas. We combine GAN and autoencoder for defect image reconstruction and use LBP for image local contrast to detect defects. In the training process of the algorithm, only positive samples is needed, without defect samples and manual label. This paper carries out verification experiments for concentrated fabric images and the dataset of DAGM 2007. Experiments show that the proposed GAN+LBP algorithm and supervised training algorithm with sufficient training samples have fairly high detection accuracy. Because of its unsupervised characteristics, it has higher practical application value. 

个人总结：详细分析：https://blog.csdn.net/qq_27871973/article/details/84068984

### [2]GAN用于异常检测

论文题目：GANomaly: Semi-Supervised Anomaly Detection via Adversarial Training   [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

论文摘要：Anomaly detection is a classical problem in computer vision, namely the determination of the normal from the abnormal when datasets are highly biased towards one class (normal) due to the insufficient sample size of the other class (abnormal). While this can be addressed as a supervised learning problem, a significantly more challenging problem is that of detecting the unknown/unseen anomaly case that takes us instead into the space of a one-class, semi-supervised learning paradigm. We introduce such a novel anomaly detection model, by using a conditional generative adversarial network that jointly learns the generation of high-dimensional image space and the inference of latent space. Employing encoder-decoder-encoder sub-networks in the generator network enables the model to map the input image to a lower dimension vector, which is then used to reconstruct the generated output image. The use of the additional encoder network maps this generated image to its latent representation. Minimizing the distance between these images and the latent vectors during training aids in learning the data distribution for the normal samples. As a result, a larger distance metric from this learned data distribution at inference time is indicative of an outlier from that distribution | an anomaly. Experimentation over several benchmark datasets, from varying domains, shows the model efficacy and superiority over previous state-of-the-art approaches. 

### [3]GAN用于缺陷分类

论文题目：Surface defect classification of steels with a new semi-supervised learning method [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

论文摘要：Defect inspection is extremely crucial to ensure the quality of steel surface. It affects not only the subsequent production, but also the quality of the end-products. However, due to the rare occurrence and appearance variations of defects, surface defect identification of steels has always been a challenging task. Recently, deep learning methods have shown outstanding performance in image classification, especially when there are enough training samples. Since most sample images of steel surface are unlabeled, a new semi-supervised learning method is proposed to classify surface defects of steels. The new method is named CAE-SGAN, as it is based on Convolutional Autoencoder (CAE) and semi-supervised Generative Adversarial Networks (SGAN). CAE-SGAN first trains a stacked CAE through massive unlabeled data. Considering the appearance variations of defects, the passthrough layer is used to help CAE extract fine-grained features. After CAE is trained, the encoder network of CAE is reserved as the feature extractor and fed into a softmax layer to form a new classifier. SGAN is introduced for semi-supervised learning to further improve the generalization ability of the new method. The classifier is trained with images collected from real production lines and images randomly generated by SGAN. Extensive experiments are carried out with samples captured from different steel production lines, and the results indicate that CAESGAN had yielded best performances compared with traditional methods. Especially for hot rolled plates, the classification rate is improved by around 16%. 

### [4]YOLO用于缺陷检测

论文题目：Real-time Detection of Steel Strip Surface Defects Based on Improved YOLO Detection Network [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

论文摘要：The surface defects of steel strip have diverse and complex features, and surface
defects caused by different production lines tend to have different characteristics. Therefore,
the detection algorithms for the surface defects of steel strip should have good generalization
performance. Aiming at detecting surface defects of steel strip, we established a dataset of six
types of surface defects on cold-rolled steel strip and augmented it in order to reduce over-fitting.
We improved the You Only Look Once (YOLO) network and made it all convolutional. Our improved network, which consists of 27 convolution layers, provides an end-to-end solution for
the surface defects detection of steel strip. We evaluated the six types of defects with our network
and reached performance of 97.55% mAP and 95.86% recall rate. Besides, our network achieves
99% detection rate with speed of 83 FPS, which provides methodological support for real-time
surface defects detection of steel strip. It can also predict the location and size information of
defect regions,  which is of great significance for evaluating the quality of an entire steel strip
production line.

## 2019.10

### [1]半监督方法的异常检测

论文题目：A semi-supervised convolutional neural network-based method for steel [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

论文摘要：Automatic defect recognition is one of the research hotspots in steel production, but most of the current methods focus on supervised learning, which relies on large-scale labeled samples. In some real-world cases, it is difcult to collect and label enough samples for model training, and this might impede the application of most current works. The semi-supervised learning, using both labeled and unlabeled samples for model training, can overcome this problem well. In this paper, a semi-supervised learning method using the convolutional neural network (CNN) is proposed for steel surface defect recognition. The proposed method requires fewer labeled samples, and the unlabeled data can be used to help training. And, the CNN is improved by Pseudo-Label. The experimental results on a benchmark dataset of steel surface defect recognition indicate that the proposed method can achieve good performances with limited labeled data, which achieves an accuracy of 90.7% with 17.53% improvement. Furthermore, the proposed method has been applied to a real-world case from a Chinese steel company, and obtains an accuracy of 86.72% which signifcantly better than the original method in this workshop. 

### [2]小样本下用语义分割方法做检测

论文题目：Segmentation-based deep-learning approach for surface-defect detection [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

论文摘要：Automated surface-anomaly detection using machine learning has become an interesting and promising area of research, with a very high and direct impact on the application domain of visual inspection. Deep-learning methods have become the most suitable approaches for this task. They allow the inspection system to learn to detect the surface anomaly by simply showing it a number of exemplar images. This paper presents a segmentation-based deep-learning architecture that is designed for the detection and segmentation of surface anomalies and is demonstrated on a specific domain of surface-crack detection. The design of the architecture enables the model to be trained using a small number of samples, which is an important requirement for practical applications. The proposed model is compared with the related deep-learning methods, including the state-ofthe-art commercial software, showing that the proposed approach outperforms the related methods on the specific domain of surface-crack detection. The large number of experiments also shed light on the required precision of the annotation, the number of required training samples and on the required computational cost. Experiments are performed on a newly created dataset based on a real-world quality control case and demonstrates that the proposed approach is able to
learn on a small number of defected surfaces, using only approximately 25-30 defective training samples, instead of hundreds or thousands, which is usually the case in deeplearning applications. This makes the deep-learning method practical for use in industry where the number of available defective samples is limited. The dataset is also made publicly available to encourage the development and evaluation of new methods for surface-defect detection. 

### [3]SDD-CNN用于检测

论文题目：SDD-CNN: Small Data-Driven Convolution Neural Networks for Subtle Roller Defect Inspection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

论文摘要：Roller bearings are some of the most critical and widely used components in rotating machinery. Appearance defect inspection plays a key role in bearing quality control. However, in real industries, bearing defects are usually extremely subtle and have a low probability of occurrence. This leads to distribution discrepancies between the number of positive and negative samples, which makes intelligent data-driven inspection methods difficult to develop and deploy. This paper presents a small data-driven convolution neural network (SDD-CNN) for roller subtle defect inspection via an ensemble method for small data preprocessing. First, label dilation (LD) is applied to solve the problem of an imbalance in class distribution. Second, a semi-supervised data augmentation (SSDA) method is proposed to extend the dataset in a more efficient and controlled way. In this method, a coarse CNN model is trained to generate ground truth class activation and guide the random cropping of images. Third, four variants of the CNN model, namely, SqueezeNet v1.1, Inception v3, VGG-16, and ResNet-18, are introduced and employed to inspect and classify the surface defects of rollers. Finally, a rich set of experiments and assessments is conducted, indicating that these SDD-CNN models, particularly the SDD-Inception v3 model, perform exceedingly well in the roller defect classification task with a top-1 accuracy reaching 99.56%. In addition, the convergence time and classification accuracy for an SDD-CNN model achieve significant improvement compared to that for the original CNN. Overall, using an SDD-CNN architecture, this paper provides a clear path toward a higher precision and efficiency for roller defect inspection in smart manufacturing. 

## 2019.11

### [1] FCN用于缺陷检测

论文题目：A High-Efficiency Fully Convolutional Networks for Pixel-Wise Surface Defect Detection [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.11" target="_blank">paper</a>]

论文摘要：In this paper, we propose a highly efficient deep learning-based method for pixel-wise surface
defect segmentation algorithm in machine vision. Our method is composed of a segmentation stage (stage
1), a detection stage (stage 2), and a matting stage (stage 3). In the segmentation stage, a lightweight
fully convolutional network (FCN) is employed to make a pixel-wise prediction of the defect areas. Those
predicted defect areas act as the initialization of stage 2, guiding the process of detection to correct the
improper segmentation. In the matting stage, a guided filter is utilized to refine the contour of the defect
area to reflect the real abnormal region. Besides that, aiming to achieve the tradeoff between efficiency and
accuracy, and simultaneously we use depthwise&pointwise convolution layer, strided depthwise convolution layer, and upsample depthwise convolution layer to replace the standard convolution layer, pooling layer, and deconvolution layer, respectively. We validate our findings by analyzing the performance obtained on the dataset of DAGM 2007. 

### [2] 布匹缺陷检测

又一篇比较不错的GAN网络做表面异常检测，值得细看哈！

论文题目：Unsupervised fabric defect detection based on a deep convolutional generative adversarial network [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.11" target="_blank">paper</a>]

论文摘要：Detecting and locating surface defects in textured materials is a crucial but challenging problem due to factors such as texture variations and lack of adequate defective samples prior to testing. In this paper we present a novel unsupervised method for automatically detecting defects in fabrics based on a deep convolutional generative adversarial network (DCGAN). The proposed method extends the standard DCGAN, which consists of a discriminator and a generator, by introducing a new encoder component. With the assistance of this encoder, our model can reconstruct a given query image such that no defects but only normal textures will be preserved in the reconstruction. Therefore, when subtracting the reconstruction from the original image, a residual map can be created to highlight potential defective regions. Besides, our model generates a likelihood map for the image under inspection where each pixel value indicates the probability of occurrence of defects at that location. The residual map and the likelihood map are then synthesized together to form an enhanced fusion map. Typically, the fusion map exhibits uniform gray levels over defect-free regions but distinct deviations over defective areas, which can be further thresholded to produce a binarized segmentation result. Our model can be unsupervisedly trained by feeding with a set of small-sized image patches picked from a few defect-free examples. The training is divided into several successively performed stages, each under an individual training strategy. The performance of the proposed method has been extensively evaluated by a variety of real fabric samples.
The experimental results in comparison with other methods demonstrate its effectiveness in fabric defect detection. 

<br>
* *Update by Sep 29，2020 @Charmve
