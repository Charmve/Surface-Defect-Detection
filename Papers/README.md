<div id="outputFigDisplay" class="fig" align="center">
    <pre id="taag_output_text" style="float:left;" class="flag" contenteditable="true">
    ____  _                                        
  / ___|| |__    __ _  _ __  _ __ ___ __   __ ___ 
 | |    | '_ \  / _` || '__|| '_ ` _ \\ \ / // _ \
 | |___ | | | || (_| || |   | | | | | |\ V /|  __/
     \____||_| |_| \__,_||_|   |_| |_| |_| \_/  \___|   
    </pre>
</div>

<p align="center">
   <a href="https://github.com/Charmve"><img src="https://img.shields.io/badge/Github-Charmve-blue" alt="Github" target="_blank"></a>
   <img src="https://img.shields.io/badge/language-English-green" alt="English Version" >
   <a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/README_Chinese.md" target="_blank"><img src="https://img.shields.io/badge/language-Chinese-red" alt="Chinese Version"></a>
</p>


# -Surface Defect Detection Papers-
🐎📈 collecting Surface-Defect-Detection paper and dataset 🐋

This repo is sharing some articles on surface defect inspection, the main inspection objects are: metal surface, LCD screen, building, transmission line and other defects or abnormal inspection objects. The methods are mainly classified method, detection method, reconstruction method and generation method. The electronic version (PDF) of the paper is placed under the file named corresponding to the date in the ``'Paper'`` folder.

## 2019.01

### [1]CNN for Classfication

<strong>Paper</strong>：A fast and robust convolutional neural network-based defect detection model in product quality control  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/A%20fast%20and%20robust%20convolutional%20neural%20network-based%20defect%20detection%20model%20in%20product%20quality%20control.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：The fast and robust automated quality visual inspection has received increasing attention in the product quality control for production efficiency. To effectively detect defects in products, many methods focus on the handcrafted optical features. However, these methods tend to only work well under specified conditions and have many requirements for the input. So the work in this paper targets on building a deep model to solve this problem. The elaborately designed deep convolutional neural networks (CNN) proposed by us can automatically extract powerful features with less prior knowledge about the images for defect detection, while at the same time is robust to noise. We experimentally evaluate this CNN model on a benchmark dataset and achieve a fast detection result with a high accuracy, surpassing the state-of-the-art methods. 

<strong>Conclusion personally</strong>：A magazine article in July 2017. The author uses a multi-layer CNN network to classify the six types of defect samples in the DAGM2007 data set. After the classification is completed, defect detection is performed on each type of sample. 

The specific methods are: 

1. Use the sliding-window method to sample on the 512×512 original image, the sampling size is 128×128; 

2. Perform two classifications on the small image blocks after each type of image sampling in the above part (with defects) And no defects). The final experiment is compared with previous traditional methods, such as SIFT+SVM, and the effect is good. The following figure shows the CNN network used for the two classifications of the article. 

The difference between the two classifications is: 
1. The input of the fully connected layer is 6 and 2 respectively; 

2. The input image size is different.

### [2] Image pyramid hierarchy idea and convolutional denoising autoencoder network to detect texture defects

<strong>Paper</strong>：An Unsupervised-Learning-Based Approach for Automated Defect Inspection on Textured Surfaces [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/An%20Unsupervised-Learning-Based%20Approach%20for%20Automated%20Defect%20Inspection%20on%20Textured%20Surfaces.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：Automated defect inspection has long been a challenging task especially in industrial applications, where collecting and labeling large amounts of defective samples are usually harsh and impracticable. In this paper, we propose an approach to detect and localize defects with only defect-free samples for model

<strong>training</strong>. This approach is carried out by reconstructing image patches with convolutional denoising autoencoder networks at different Gaussian pyramid levels, and synthesizing detection results from these different resolution channels. Reconstruction residuals of the training patches are used as the indicator for
direct pixelwise defect prediction, and the reconstruction residual map generated in each channel is combined to generate the final inspection result. This novel method has two prominent characteristics, which benefit the implementation of automatic defect inspection in practice. First, it is absolutely unsupervised that no human intervention is needed throughout the inspection process. Second, multimodal strategy is utilized in this method to synthesize results from multiple pyramid levels. This strategy is capable of improving the robustness and accuracy of the method. To evaluate this approach, experiments on convergence, noise immunity, and defect inspection accuracy are conducted. Furthermore, comparative tests with some excellent algorithms on actual and simulated data sets are performed. Experimental results demonstrated the effectiveness and superiority of the proposed method on homogeneous and nonregular textured surfaces. 

<strong>Conclusion personally</strong>：A magazine article in June 2018. The article is basically the same as the core content of the article "<i>Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model</i>" in another magazine in April, and the author is the same person. 

- Main framework: Combine the idea of image pyramid hierarchy and convolutional denoising autoencoder network (CDAE) to detect texture image defects. 
- Specific implementation: Reconstruct image patches using convolutional denoising autoencoder networks of different Gaussian pyramid levels, use the reconstruction residuals of training patches as indicators for direct pixel direction defect prediction, and use the reconstructed residual maps generated by each channel Combine them to generate the final test result. The paper is an unsupervised method for defect detection. The effect is very good on the atlas with strong repetitive background textures such as cloth silk fabrics, and the effect on metal surfaces and processed parts surface data sets is average or even poor. In the last part of the experiment, the author also used the DAGM2007 data set to do the test. The effect is average, far from meeting the requirements of industrial applications, but compared with other methods, some types of effects have improved.

### [3] Cascade autoencoder (CASAE) structure is used for segmentation and positioning of abnormal metal surface

<strong>Paper</strong>：Automatic Metallic Surface Defect Detection and Recognition with Convolutional Neural Networks [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/Automatic_Metallic_Surface_Defect_Detection_and_Re.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：Automatic metallic surface defect inspection has received increased attention in relation
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

<strong>Conclusion personally</strong>：A magazine article in September 2018. The author proposes a detection method for metal surface defects. With the help of the performance of the autoencoder in image reconstruction, a Cascaded Autoencoder (CASAE) architecture is designed for the segmentation and location of metal surface anomalies. Then use CNN to classify the segmented defect areas. The specific pipeline is as follows. Overall, the idea of the article is rough semantic segmentation + convolution fine classification.

Detailed analysis can be seen in this blog：https://blog.csdn.net/qq_27871973/article/details/83817694

### [4]Faster R-CNN用于土木行业缺陷检测

<strong>Paper</strong>：Autonomous Structural Visual Inspection Using Region-Based Deep Learning for Detecting Multiple Damage Types [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.01/Autonomous%20Structural%20Visual%20Inspection%20Using%20Region-Based%20Deep%20Learning%20for%20Detecting%20Multiple%20Damage%20Types.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>： Computer vision-based techniques were developed to overcome the limitations of visual inspection by trained human resources and to detect structural damage in images remotely, but most methods detect only specific types of damage, such as concrete or steel cracks. To provide quasi real-time simultaneous detection of multiple types of damages, a Faster Region-based Convolutional Neural Network (Faster R-CNN)-based structural visual inspection method is proposed. To realize this, a database including 2,366 images (with 500 × 375 pixels) labeled for five types of damages—concrete crack, steel corrosion with two levels (medium and high), bolt corrosion, and steel delamination—is developed. Then, the architecture of the Faster R-CNN is modified, trained, validated, and tested using this database. Results show 90.6%, 83.4%, 82.1%, 98.1%, and 84.7% average precision (AP) ratings for the five damage types, respectively, with a mean AP of 87.8%. The robustness of the trained Faster R-CNN is evaluated and demonstrated using 11 new 6,000 × 4,000-pixel images taken of different structures. Its performance is also compared to that of the traditional CNN-based method. Considering that the proposed method provides a remarkably fast test speed (0.03 seconds per image with 500 × 375 resolution), a framework for quasi real-time damage detection on video using the trained networks is developed. 

<strong>Conclusion personally</strong>：A magazine article in 2018. The article uses Faster R-CNN for concrete in the field of civil engineering. For damage detection such as steel cracks, the article mainly transfers Faster R-CNN to industry detection, which can be regarded as the actual combat of the Faster R-CNN model.

## 2019.02

### [1] Active learning for defect classification

<strong>Paper</strong>：Deep Active Learning for Civil Infrastructure Defect Detection and Classification [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Deep%20Active%20Learning%20for%20Civil%20Infrastructure%20Defect%20detection%20and%20clssification.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：Automatic detection and classification of defects in infrastructure surface images can largely
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

<strong>Conclusion personally</strong>：Active learning ideas combine with ResNet network to classify industry defect samples to improve accuracy.

### [2] An experiment of CNN: LCD screen anomaly detection

<strong>Paper</strong>：Defect Detection of Mobile Phone Surface Based on Convolution Neural Network  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Defect%20Detection%20of%20Mobile%20Phone%20Surface%20based%20on%20convlution%20nerual%20networks.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：Automatic surface defect detection of mobile phone in large scale needs to
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

### [3] Deep learning & Transfer Learning

<strong>Paper</strong>：Defects Detection Based on Deep Learning and Transfer Learning  [<a href="https://github.com/Charmve/Surface-Defect-Detection/blob/master/Papers/2019.02/Defects%20Detection%20Based%20on%20Deep%20Learning%20and%20Transfer%20Learning.pdf" target="_blank">paper</a>]

<strong>Abstract</strong>：Defect detection is an important step in the feld of industrial production. Through the study of deep
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

### [1] Segmentation Network for Magnetic Tile Defect Detection

<strong>Paper</strong>：Surface Defect Saliency of Magnetic Tile  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

<strong>Abstract</strong>：Vision-based detection on surface defects has long postulated in the magnetic tile automation process. In this work, we introduce a real-time and multi-module neural network model called MCuePush U-Net, specifically designed for the image saliency detection of magnetic tile. We show that the model exceeds the state-of-the-art, in which it both effectively and explicitly maps multiple surface defects from low-contrast images. Our model significantly reduces time cost of machinery from 0.5s per image to 0.07s, and enhances saliency accuracy on surface defect detection. 

### [2] Classic PHOTO Algorithm

<strong>Paper</strong>：The Phase Only Transform for unsupervised surface defect detection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

<strong>Abstract</strong>：We present a simple, fast, and effective method to detect defects on textured surfaces. Our method is unsupervised and contains no learning stage or information on the texture being inspected. The new method is based on the Phase Only Transform (PHOT) which correspond to the Discrete Fourier Transform (DFT), normalized by the magnitude. The PHOT removes any regularities, at arbitrary
scales, from the image while preserving only irregular patterns considered to represent defects. The localization is obtained by the inverse transform followed by adaptive thresholding using a simple standard statistical method. The main computational requirement is thus to apply the DFT on the input image. The new method is also easy to implement in a few lines of code. Despite its simplicity, the methods is
shown to be effective and generic as tested on various inputs, requiring only one parameter for sensitivity. We provide theoretical justification based on a simple model and show results on various kinds of patterns. We also discuss some limitations. 

### [3] Classic DCT Algorithm

<strong>Paper</strong>：Tiny surface defect inspection of electronic passive components using discrete cosine transform decomposition and cumulative sum techniques [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.03" target="_blank">paper</a>]

<strong>Abstract</strong>：Passive components, owing to their low or no power consumption, are widely used in modern electronic devices. Nevertheless, tiny defects that often appear in the surface of passive components impair not only their appearances but also their functions. This paper proposes a global approach for the automated visual inspection of tiny surface defects in SBL (Surface Barrier Layer) chips, whose random surface texture contains no repetitions of basic texture primitives. The proposed method, taking advantage of the DCT decomposition and the cumulative sum techniques, does not requires textural features, the lack of which often limits the application of feature extraction-based methods. We apply the cumulative sum algorithm to the odd–odd matrix that gathers most power spectra in the decomposed DCT frequency domain, and select the large-magnitude frequency values that represent the background texture of the surface. Then, by reconstructing the frequency matrix without the selected frequency values, we eliminate random texture patterns and retain anomalies in the restored image. Experimental results demonstrate the effectiveness of the proposed method in inspecting tiny defects in random textures. 

## 2019.04

### [1] An unsupervised scanning electron microscope image (SEM) detection method for nanofiber materials

<strong>Paper</strong>：Anomaly Detection in Nanofibrous Materials by CNN-Based Self-Similarity [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

<strong>Abstract</strong>：Automatic detection and localization of anomalies in nanofibrous materials help to reduce
the cost of the production process and the time of the post-production visual inspection process.
Amongst all the monitoring methods, those exploiting Scanning Electron Microscope (SEM) imaging
are the most effective. In this paper, we propose a region-based method for the detection and
localization of anomalies in SEM images, based on Convolutional Neural Networks (CNNs) and
self-similarity. The method evaluates the degree of abnormality of each subregion of an image
under consideration by computing a CNN-based visual similarity with respect to a dictionary of
anomaly-free subregions belonging to a training set. The proposed method outperforms the state
of the art. 

<strong>Conclusion personally</strong>：For detailed analysis, see https://blog.csdn.net/qq_27871973/article/details/86007150

### [2] Faster R-CNN is used for concrete in the field of civil engineering

<strong>Paper</strong>：Automatic Defect Detection of Fasteners on theCatenary Support Device Using Deep
Convolutional Neural Network  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

<strong>Abstract</strong>：The excitation and vibration triggered by the longterm operation of railway vehicles inevitably result in defective states of catenary support devices. With the massive construction of high-speed electrified railways, automatic defect detection of diverse and plentiful fasteners on the catenary support device
is of great significance for operation safety and cost reduction. Nowadays, the catenary support devices are periodically captured by the cameras mounted on the inspection vehicles during the night, but the inspection still mostly relies on human visual interpretation. To reduce the human involvement, this paper
proposes a novel vision-based method that applies the deep convolutional neural networks (DCNNs) in the defect detection of the fasteners. Our system cascades three DCNN-based detection stages in a coarse-to-fine manner, including two detectors to sequentially localize the cantilever joints and their fasteners and a
classifier to diagnose the fasteners’ defects. Extensive experiments and comparisons of the defect detection of catenary support devices along the Wuhan–Guangzhou high-speed railway line indicate that the system can achieve a high detection rate with good adaptation and robustness in complex environments. 

<strong>Conclusion personally</strong>：A journal paper in February 2018. The author applies deep convolutional neural networks (DCNNs) to the defect detection of fasteners on high-speed railway lines. Combining network methods such as SSD and YOLO, a cascade detection network from coarse to fine is constructed, including: two detectors to locate the cantilever node and its fasteners, and a classifier to classify fastener defects. Especially in the experimental part, the author has done enough.

### [3] Multi-scale Convolutional Denoising Autoencoder Network Model

<strong>Paper</strong>：Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.04" target="_blank">paper</a>]

<strong>Abstract</strong>：Fabric defect detection is a necessary and essential step of quality control in the textile
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

<strong>Conclusion personally</strong>：The core idea is the same as the second part of 2019.01.

## 2019.05

### [1] CNN for Classfication

<strong>Paper</strong>：Design of deep convolutional neural network architectures for automated feature extraction in industrial inspection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

<strong>Abstract</strong>：Fast and reliable industrial inspection is a main challenge in manufacturing scenarios. However, the defect
detection performance is heavily dependent on manually defined features for defect representation. In
this contribution, we investigate a new paradigm from machine learning, namely deep machine learning
by examining design configurations of deep Convolutional Neural Networks (CNN) and the impact of
different hyper-parameter settings towards the accuracy of defect detection results. In contrast to
manually designed image processing solutions, deep CNN automatically generate powerful features by
hierarchical learning strategies from massive amounts of training data with a minimum of human
interaction or expert process knowledge. An application of the proposed method demonstrates excellent
defect detection results with low false alarm rates. 

### [2] Weibull

<strong>Paper</strong>：Non-parametric texture defect detection using Weibull features [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

<strong>Abstract</strong>：The detection of abnormalities is a very challenging problem in computer vision, especially if these abnormalities must be detected in images of textured surfaces such as textile, stone, or wood. We propose a novel, nonparametric approach for defect detection in textures that only employs two features. We compute the two parameters of a Weibull fit for the distribution of image gradients in local regions. Then, we perform a simple novelty detection algorithm in order to detect arbitrary deviations of the reference texture. Therefore, we evaluate the Euclidean distances of all local patches to a reference point in the Weibull space, where the reference point is determined for each texture image individually. Thus, our approach becomes independent of the particular texture type and also independent of a certain defect type.
For performance evaluation we use the highly challenging database provided by Bosch for a contest on
industrial optical inspection with different classes of textures and different defect types. By using the Weibull parameters we can detect local deviations of texture images in an unsupervised manner with high accuracy. Compared to existing approaches such as Gabor filters or grey level statistics, our approach is not only powerful, but also very efficient such that it can also be applied for real-time applications. 

### [3] Neuro-Evolution

<strong>Paper</strong>：Learning Defect Classifiers for Visual Inspection Images by Neuro-Evolution using Weakly Labelled Training Data  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.05" target="_blank">paper</a>]

<strong>Abstract</strong>： This article presents results from experiments where a detector for defects in visual inspection images was learned from scratch by EANT2, a method for evolutionary reinforcement learning. The detector is constructed as a neural network that takes as input statistical data on filter responses
from a bank of image filters applied to an image region. Training is done on example images with weakly labelled defects. Experiments show good results of EANT2 in an application area where evolutionary methods are rare. 

## 2019.06

### [1] GAN for Defect Detection

<strong>Paper</strong>：A Surface Defect Detection Method Based on Positive Samples  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

<strong>Abstract</strong>：Surface defect detection and classification based on machine vision can greatly improve the efficiency of industrial production. With enough labeled images, defect detection methods based on convolution neural network have achieved the detection effect of state-of-art. However in practical applications, the defect samples or negative samples are usually difficult to be collected before‐
hand and manual labelling is time-consuming. In this paper, a novel defect detection framework only based on training of positive samples is proposed. The basic detection concept is to establish a reconstruction network which can repair defect areas in the samples if they are existed, and then make a comparison between the input sample and the restored one to indicate the accurate defect areas. We combine GAN and autoencoder for defect image reconstruction and use LBP for image local contrast to detect defects. In the training process of the algorithm, only positive samples is needed, without defect samples and manual label. This paper carries out verification experiments for concentrated fabric images and the dataset of DAGM 2007. Experiments show that the proposed GAN+LBP algorithm and supervised training algorithm with sufficient training samples have fairly high detection accuracy. Because of its unsupervised characteristics, it has higher practical application value. 

<strong>Conclusion personally</strong>：More details would be presented in this blog：https://blog.csdn.net/qq_27871973/article/details/84068984

### [2] GAN for Anomaly Detection

<strong>Paper</strong>：GANomaly: Semi-Supervised Anomaly Detection via Adversarial Training   [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

<strong>Abstract</strong>：Anomaly detection is a classical problem in computer vision, namely the determination of the normal from the abnormal when datasets are highly biased towards one class (normal) due to the insufficient sample size of the other class (abnormal). While this can be addressed as a supervised learning problem, a significantly more challenging problem is that of detecting the unknown/unseen anomaly case that takes us instead into the space of a one-class, semi-supervised learning paradigm. We introduce such a novel anomaly detection model, by using a conditional generative adversarial network that jointly learns the generation of high-dimensional image space and the inference of latent space. Employing encoder-decoder-encoder sub-networks in the generator network enables the model to map the input image to a lower dimension vector, which is then used to reconstruct the generated output image. The use of the additional encoder network maps this generated image to its latent representation. Minimizing the distance between these images and the latent vectors during training aids in learning the data distribution for the normal samples. As a result, a larger distance metric from this learned data distribution at inference time is indicative of an outlier from that distribution | an anomaly. Experimentation over several benchmark datasets, from varying domains, shows the model efficacy and superiority over previous state-of-the-art approaches. 

### [3] GAN for Defect Classfication

<strong>Paper</strong>：Surface defect classification of steels with a new semi-supervised learning method [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

<strong>Abstract</strong>：Defect inspection is extremely crucial to ensure the quality of steel surface. It affects not only the subsequent production, but also the quality of the end-products. However, due to the rare occurrence and appearance variations of defects, surface defect identification of steels has always been a challenging task. Recently, deep learning methods have shown outstanding performance in image classification, especially when there are enough training samples. Since most sample images of steel surface are unlabeled, a new semi-supervised learning method is proposed to classify surface defects of steels. The new method is named CAE-SGAN, as it is based on Convolutional Autoencoder (CAE) and semi-supervised Generative Adversarial Networks (SGAN). CAE-SGAN first trains a stacked CAE through massive unlabeled data. Considering the appearance variations of defects, the passthrough layer is used to help CAE extract fine-grained features. After CAE is trained, the encoder network of CAE is reserved as the feature extractor and fed into a softmax layer to form a new classifier. SGAN is introduced for semi-supervised learning to further improve the generalization ability of the new method. The classifier is trained with images collected from real production lines and images randomly generated by SGAN. Extensive experiments are carried out with samples captured from different steel production lines, and the results indicate that CAESGAN had yielded best performances compared with traditional methods. Especially for hot rolled plates, the classification rate is improved by around 16%. 

### [4]YOLO for Defect Classfication

<strong>Paper</strong>：Real-time Detection of Steel Strip Surface Defects Based on Improved YOLO Detection Network [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.06" target="_blank">paper</a>]

<strong>Abstract</strong>：The surface defects of steel strip have diverse and complex features, and surface
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

### [1] Semi-supervised Method for Anomaly Detection

<strong>Paper</strong>：A semi-supervised convolutional neural network-based method for steel [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

<strong>Abstract</strong>：Automatic defect recognition is one of the research hotspots in steel production, but most of the current methods focus on supervised learning, which relies on large-scale labeled samples. In some real-world cases, it is difcult to collect and label enough samples for model training, and this might impede the application of most current works. The semi-supervised learning, using both labeled and unlabeled samples for model training, can overcome this problem well. In this paper, a semi-supervised learning method using the convolutional neural network (CNN) is proposed for steel surface defect recognition. The proposed method requires fewer labeled samples, and the unlabeled data can be used to help training. And, the CNN is improved by Pseudo-Label. The experimental results on a benchmark dataset of steel surface defect recognition indicate that the proposed method can achieve good performances with limited labeled data, which achieves an accuracy of 90.7% with 17.53% improvement. Furthermore, the proposed method has been applied to a real-world case from a Chinese steel company, and obtains an accuracy of 86.72% which signifcantly better than the original method in this workshop. 

### [2] Use semantic segmentation methods for detection under small samples

<strong>Paper</strong>：Segmentation-based deep-learning approach for surface-defect detection [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

<strong>Abstract</strong>：Automated surface-anomaly detection using machine learning has become an interesting and promising area of research, with a very high and direct impact on the application domain of visual inspection. Deep-learning methods have become the most suitable approaches for this task. They allow the inspection system to learn to detect the surface anomaly by simply showing it a number of exemplar images. This paper presents a segmentation-based deep-learning architecture that is designed for the detection and segmentation of surface anomalies and is demonstrated on a specific domain of surface-crack detection. The design of the architecture enables the model to be trained using a small number of samples, which is an important requirement for practical applications. The proposed model is compared with the related deep-learning methods, including the state-ofthe-art commercial software, showing that the proposed approach outperforms the related methods on the specific domain of surface-crack detection. The large number of experiments also shed light on the required precision of the annotation, the number of required training samples and on the required computational cost. Experiments are performed on a newly created dataset based on a real-world quality control case and demonstrates that the proposed approach is able to
learn on a small number of defected surfaces, using only approximately 25-30 defective training samples, instead of hundreds or thousands, which is usually the case in deeplearning applications. This makes the deep-learning method practical for use in industry where the number of available defective samples is limited. The dataset is also made publicly available to encourage the development and evaluation of new methods for surface-defect detection. 

### [3]SDD-CNN for Defect Detection

<strong>Paper</strong>：SDD-CNN: Small Data-Driven Convolution Neural Networks for Subtle Roller Defect Inspection  [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.10" target="_blank">paper</a>]

<strong>Abstract</strong>：Roller bearings are some of the most critical and widely used components in rotating machinery. Appearance defect inspection plays a key role in bearing quality control. However, in real industries, bearing defects are usually extremely subtle and have a low probability of occurrence. This leads to distribution discrepancies between the number of positive and negative samples, which makes intelligent data-driven inspection methods difficult to develop and deploy. This paper presents a small data-driven convolution neural network (SDD-CNN) for roller subtle defect inspection via an ensemble method for small data preprocessing. First, label dilation (LD) is applied to solve the problem of an imbalance in class distribution. Second, a semi-supervised data augmentation (SSDA) method is proposed to extend the dataset in a more efficient and controlled way. In this method, a coarse CNN model is trained to generate ground truth class activation and guide the random cropping of images. Third, four variants of the CNN model, namely, SqueezeNet v1.1, Inception v3, VGG-16, and ResNet-18, are introduced and employed to inspect and classify the surface defects of rollers. Finally, a rich set of experiments and assessments is conducted, indicating that these SDD-CNN models, particularly the SDD-Inception v3 model, perform exceedingly well in the roller defect classification task with a top-1 accuracy reaching 99.56%. In addition, the convergence time and classification accuracy for an SDD-CNN model achieve significant improvement compared to that for the original CNN. Overall, using an SDD-CNN architecture, this paper provides a clear path toward a higher precision and efficiency for roller defect inspection in smart manufacturing. 

## 2019.11

### [1] FCN for Defect Detection

<strong>Paper</strong>：A High-Efficiency Fully Convolutional Networks for Pixel-Wise Surface Defect Detection [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.11" target="_blank">paper</a>]

<strong>Abstract</strong>：In this paper, we propose a highly efficient deep learning-based method for pixel-wise surface
defect segmentation algorithm in machine vision. Our method is composed of a segmentation stage (stage
1), a detection stage (stage 2), and a matting stage (stage 3). In the segmentation stage, a lightweight
fully convolutional network (FCN) is employed to make a pixel-wise prediction of the defect areas. Those
predicted defect areas act as the initialization of stage 2, guiding the process of detection to correct the
improper segmentation. In the matting stage, a guided filter is utilized to refine the contour of the defect
area to reflect the real abnormal region. Besides that, aiming to achieve the tradeoff between efficiency and
accuracy, and simultaneously we use depthwise&pointwise convolution layer, strided depthwise convolution layer, and upsample depthwise convolution layer to replace the standard convolution layer, pooling layer, and deconvolution layer, respectively. We validate our findings by analyzing the performance obtained on the dataset of DAGM 2007. 

### [2] Fabric Defect Detection

Another good GAN network for surface anomaly detection is worth a closer look!

<strong>Paper</strong>：Unsupervised fabric defect detection based on a deep convolutional generative adversarial network [<a href="https://github.com/Charmve/Surface-Defect-Detection/tree/master/Papers/2019.11" target="_blank">paper</a>]

<strong>Abstract</strong>：Detecting and locating surface defects in textured materials is a crucial but challenging problem due to factors such as texture variations and lack of adequate defective samples prior to testing. In this paper we present a novel unsupervised method for automatically detecting defects in fabrics based on a deep convolutional generative adversarial network (DCGAN). The proposed method extends the standard DCGAN, which consists of a discriminator and a generator, by introducing a new encoder component. With the assistance of this encoder, our model can reconstruct a given query image such that no defects but only normal textures will be preserved in the reconstruction. Therefore, when subtracting the reconstruction from the original image, a residual map can be created to highlight potential defective regions. Besides, our model generates a likelihood map for the image under inspection where each pixel value indicates the probability of occurrence of defects at that location. The residual map and the likelihood map are then synthesized together to form an enhanced fusion map. Typically, the fusion map exhibits uniform gray levels over defect-free regions but distinct deviations over defective areas, which can be further thresholded to produce a binarized segmentation result. Our model can be unsupervisedly trained by feeding with a set of small-sized image patches picked from a few defect-free examples. The training is divided into several successively performed stages, each under an individual training strategy. The performance of the proposed method has been extensively evaluated by a variety of real fabric samples.

The experimental results in comparison with other methods demonstrate its effectiveness in fabric defect detection. 


# Repo: PaperWeeklyAI

https://github.com/Charmve/PaperWeeklyAI

Study papers in the fields of computer vision, NLP, and machine learning algorithms every week.

<p align="center">
  <a href="https://charmve.blog.csdn.net/"><img src="https://img.shields.io/badge/blog-Charmve-blue" alt="css"></a>
  <a href="https://charmve.blog.csdn.net/"><img src="https://www.geekxh.com/trending.svg?label=html" alt="html"></a>
  <a href="https://github.com/haizlin/fe-interview/stargazers"><img src="https://img.shields.io/github/stars/geekxh/hello-algorithm.svg" alt="Statr"></a>
</p>
<p align="center">
    <strong>Keep up with cutting-edge research trends and study papers every week!</strong>
</p>

<div align=center><img src="https://image.jiqizhixin.com/uploads/editor/d8595d93-e8c9-4abf-91f4-105384736912/%E5%9B%BE%E7%89%8712.jpg" height="330" width="330"></div>
<div align=center size = 3><b>△Scan with WeChat, follow me 🍉</b></div>
<br>

Starting in March this year, I adjusted the direction of open source to machine learning, computer vision, and AI related articles about cutting-edge technology dynamics. I summarized my own machine learning route and summarized the entry after entering many pits. And then, to now, the summary of top AI conference papers and cutting-edge papers study could be realized. There are menu categories at the bottom of the official account homepage.

<div align=center><img src="https://github.com/ChromeWei/PaperWeeklyAI/blob/master/Menu-MaiweiAI.jpg?raw=true" ></div> 
<p align="center">
    <b>△ Menu categories of Wechat official account 🍏</b>
</p>

<br>


### Content

| 👀 [Maiwei AI Paper Study](https://github.com/ChromeWei/PaperWeeklyAI)| 🐒 [AI Advanced Guide](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese)) | 📚 [10000 PDF openbooks](https://github.com/ChromeWei/hello-algorithm/tree/master/%E6%B8%85%E6%99%B0%E7%89%88%E7%94%B5%E5%AD%90%E4%B9%A61000%E6%9C%AC) |  🐒 [CS/IT Essential](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F)  | 🚀 [Interview Guide](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87) | 
| :--- | :---- | :--- | :--- | :--- |
| 🍄 [NLP Paper Study](https://github.com/Charmve/PaperWeeklyAI/tree/master/03_Maiwei%20AI%20PaperWeekly/01_NLP%E8%AE%BA%E6%96%87%E7%A0%94%E8%AF%BB)  | 🌽 [ML/DL Theory](https://github.com/Charmve/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese)) | 🐒 [Mind Map Collection](https://github.com/ChromeWei/hello-algorithm/tree/master/%E8%B6%85%E6%B8%85%E6%80%9D%E7%BB%B4%E5%AF%BC%E5%9B%BE100%E5%BC%A0) | 👺 [Column：OS](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F)|🍏 [Interview：C&C++](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/C%26C%2B%2B) |
| 🍐 [CV Top Con](https://github.com/Charmve/PaperWeeklyAI/tree/master/03_Maiwei%20AI%20PaperWeekly/02_%E8%AE%A1%E7%AE%97%E6%9C%BA%E8%A7%86%E8%A7%89%E8%AE%BA%E6%96%87) | 🍉 [Machine Learning in Action](https://github.com/Charmve/PaperWeeklyAI/tree/master/04_AppliedML) | 👺 [PDF：ML&DL](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese))|  📡 [Column：Network](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BD%91%E7%BB%9C) | 🍖 [Interview：架构师](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/%E6%9E%B6%E6%9E%84%E5%B8%88)|
| 📡 [AI Paper Must-read (10)](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese)/05_AI%E8%AE%BA%E6%96%87%E5%BF%85%E8%AF%BB%E7%AF%87%E7%9B%AE10%E7%AF%87) | 📚 [PDF：Machine Learning/Linux](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese)) | 📝 [PDF：Code & Algorithm](https://github.com/Charmve/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese))  | 📺 [Column：Unix/Linux](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/Linux) | 🚀 [Interview：Python](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/Python) |🍇 [Interview：Java](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/Java) |
|🎅 [CVPR2020 Papers (30)](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese)/06_CVPR2020%E8%AE%BA%E6%96%8730%E7%AF%87)  | 🚀 [Python学习](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/Python) | 📚 [Interview：Network Program](https://github.com/ChromeWei/PaperWeeklyAI/tree/master/00_GuideBooksPDF(English%2BChinese))|🎅 [Column：Mysql](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/Mysql)  |🍄 [Interview：Mysql](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/Mysql) |🍅 [Interview：Front-end Dep](https://github.com/ChromeWei/hello-algorithm/tree/master/%E5%A4%A7%E5%8E%82%E9%9D%A2%E7%BB%8F%E6%B1%87%E6%80%BB100%E7%AF%87/%E5%89%8D%E7%AB%AF)  |
| 🌽 [AppliedML](https://github.com/Charmve/PaperWeeklyAI/tree/master/04_AppliedML) | 📝 [Column：Jianzhi Offer](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/%E5%89%91%E6%8C%87offer)  |  | 🆎 [Column：Design Model](https://github.com/ChromeWei/hello-algorithm/tree/master/%E4%B8%93%E6%A0%8F/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F) |


<br>

<br>
* <i>Update by Sep 29，2020 @[<a href="https://github.com/Charmve" target="_blank">Charmve</a>],follow me</i>
