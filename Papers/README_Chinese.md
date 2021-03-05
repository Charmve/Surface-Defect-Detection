# surface-defect-detection
分享一些表面缺陷检测的文章，主要检测对象是：金属表面、LCD屏、建筑、输电线等缺陷或异常检物。方法以分类方法、检测方法、重构方法、生成方法为主。电子版论文放在了paper文件夹的对应日期文件下。

## 2019.01

### [1]CNN做分类

**论文题目**：A fast and robust convolutional neural network-based defect detection model in product quality control 

**摘要**：快速而强大的自动化质量视觉检查已越来越受到产品质量控制中的关注，以提高生产效率。 为了有效地检测产品中的缺陷，许多方法都集中在手工制作的光学特征上。 但是，这些方法往往只能在指定条件下才能很好地工作，并且对输入有很多要求。 因此，本文的工作旨在建立一个深度模型来解决该问题。 我们提出的精心设计的深度卷积神经网络（CNN）可以自动提取强大的功能，而无需先验图像知识就可以进行缺陷检测，同时对噪声具有鲁棒性。 我们在基准数据集上实验性地评估了该CNN模型，并获得了超越现有技术方法的高精度，快速检测结果。

**个人总结**：2017年7月的一篇杂志文章。作者使用一个多层的CNN网络对DAGM2007数据集中的六类缺陷样本进行分类，分类结束之后，对于每一类样本进行缺陷检测。

具体做法是：
1.使用sliding-window方法在512×512的原图上进行采样，采样大小为128×128；
2.对上部分每一类图像采样后的小图像块进行二分类（有缺陷和无缺陷）。最终实验和以前传统方法做的对比，比如SIFT+SVM，效果不错。

下图为文章两次分类使用的CNN网络，两次分类的区别在于：
1.全连接层的输入分别为6和2；
2.输入的图像尺寸不同。

### [2]图像金字塔层次结构思想和卷积去噪自编码器网络对纹理缺陷做检测

**论文题目**：An Unsupervised-Learning-Based Approach for Automated Defect Inspection on Textured Surfaces 

**摘要**：自动化缺陷检查长期以来一直是一项艰巨的任务，尤其是在工业应用中，在这些应用中，收集和标记大量缺陷样品通常很困难且不可行。在本文中，我们提出了一种仅使用无缺陷样本进行模型训练的检测和定位缺陷的方法。通过使用卷积降噪自编码器网络在不同的高斯金字塔等级上重建图像斑块，并合成来自这些不同分辨率通道的检测结果，来执行此方法。训练斑块的重建残差用作直接逐像素缺陷预测的指示符，并且将在每个通道中生成的重建残差图进行组合以生成最终检查结果。这种新颖的方法具有两个突出的特征，这在实践中有利于自动缺陷检测的实施。首先，绝对没有监督，在整个检查过程中都不需要人工干预。其次，该方法利用多峰策略来综合多个金字塔层次的结果。该策略能够提高该方法的鲁棒性和准确性。为了评估这种方法，进行了收敛性，抗噪性和缺陷检查精度的实验。此外，在实际和模拟数据集上使用一些出色的算法进行了对比测试。实验结果证明了该方法在均匀和不规则纹理表面上的有效性和优越性。

**个人总结**：2018年6月的一篇杂志文章。文章和4月在另一篇杂志上的《Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model》一文核心内容上基本一样，作者是同一人。

- 主要框架：结合图像金字塔层次结构思想和卷积去噪自编码器网络（CDAE）对纹理图像缺陷进行检测。
- 具体实施：利用不同高斯金字塔层次的卷积去噪自编码器网络重构image patchs，利用训练patch的重构残差作为直接像素方向缺陷预测的指标，将每个通道生成的重构残差图结合起来，生成最终的检测结果。  论文是无监督的方法做缺陷检测，在布匹丝织物这种重复性背景纹理很强的图集上效果很好，在金属表面、加工部件表面数据集效果一般，甚至很差。在最后的实验部分，作者也是用了DAGM2007数据集做了测试，效果一般，远远达不到工业应用要求，但相对其他方法，部分种类效果有提升。

### [3]级联自编码器(CASAE)结构用于金属表面异常的分割和定位

**论文题目**：Automatic Metallic Surface Defect Detection and Recognition with Convolutional Neural Networks 

**摘要**：自动金属表面缺陷检查在工业产品的质量控制方面已受到越来越多的关注。金属缺陷检测通常是针对复杂的工业场景执行的，这是一个有趣但具有挑战性的问题。传统方法是基于图像处理或浅层机器学习技术的，但是这些方法只能在特定的检测条件下检测缺陷，例如在一定范围内或在特定的照明条件下，具有明显对比度且低噪声的明显缺陷轮廓。本文讨论了一种通过双重过程自动检测金属缺陷的方法，该过程可以准确地定位和分类出现在从实际工业环境中捕获的输入图像中的缺陷。设计了一种新颖的级联自动编码器（CASAE）架构，用于分割和定位缺陷。级联网络基于语义分割将输入的缺陷图像转换为像素级预测蒙版。分割结果的缺陷区域通过紧凑卷积神经网络（CNN）分为特定类别。使用工业数据集可以成功检测各种条件下的金属缺陷。实验结果表明，该方法满足了金属缺陷检测的鲁棒性和准确性要求。同时，它也可以扩展到其他检测应用。


**个人总结**：2018年九月一篇杂志文章。作者提出来一种用于金属表面缺陷的检测方法，借助自编码器在图像重建上的性能，设计一种级联自编码器(CASAE)体系结构，用于金属表面异常的分割和定位。再利用CNN将分割后的缺陷区域做细分类。具体的pipeline如下，整体来说文章的思路就是语义粗略分割+卷积细分类。

详细的分析可以看：https://blog.csdn.net/qq_27871973/article/details/83817694

### [4]Faster R-CNN用于土木行业缺陷检测

**论文题目**：Autonomous Structural Visual Inspection Using Region-Based Deep Learning for Detecting Multiple Damage Types

**摘要**： 开发了基于计算机视觉的技术，以克服训练有素的人力资源进行视觉检查的局限性，并远程检测图像中的结构损坏，但是大多数方法仅检测特定类型的损坏，例如混凝土或钢裂缝。为了提供多种类型损伤的准实时同时检测，提出了一种基于快速区域卷积神经网络（Faster R-CNN）的结构视觉检测方法。为了实现这一目标，开发了一个数据库，其中包含2366张图像（500×375像素），这些图像分别标记了五种损坏类型：混凝土裂缝，具有两个级别（中级和高级）的钢腐蚀，螺栓腐蚀和钢分层。然后，使用此数据库修改，训练，验证和测试Faster R-CNN的体系结构。结果显示，五种损伤类型的平均精度（AP）等级分别为90.6％，83.4％，82.1％，98.1％和84.7％，平均AP为87.8％。使用11个不同结构的新6,000×4,000像素图像对经过训练的Faster R-CNN的鲁棒性进行了评估和演示。还将其性能与传统的基于CNN的方法进行了比较。考虑到所提出的方法提供了非常快的测试速度（每个图像0.03秒，具有500×375分辨率），因此开发了一种使用经过训练的网络对视频进行准实时损伤检测的框架。

**个人总结**：2018年的一篇杂志文章。文章使用Faster R-CNN用于土木建筑领域的混凝土。钢裂纹等损伤检测，文章主要是把Faster R-CNN迁移到行业检测，算是Faster R-CNN模型的实战。

## 2019.02

### [1]主动学习用于缺陷分类

**论文题目**：Deep Active Learning for Civil Infrastructure Defect Detection and Classification 

**论文摘要**：自动检测和分类基础结构表面图像中的缺陷可以大大提高其维护效率。给定足够的带标签图像，已经针对此任务研究了各种监督学习方法，包括先前研究中的决策树和支持向量机，以及最近的深度神经网络。但是，在现实应用中，由于标签资源（即专家）有限，因此标签比图像更难获得。因此，我们提出了一种深度主动学习系统，以最大限度地提高性能。首先设计一个深度残差网络，用于图像中的缺陷检测和分类。按照我们积极的学习策略，一旦有一批标记的图像可用，就会对该网络进行培训。然后，它用于从专家中选择信息最丰富的新图像子集和查询标签，以对网络进行重新培训。实验表明，与基线相比，我们的方法在性能上的改进更为有效，检测精度达到了87.5％。

**个人总结**：主动学习思想结合ResNet网络对行业缺陷样本进行分类，提升准确率。

### [2]CNN的一个实验在LCD屏异常检测

**论文题目**：Defect Detection of Mobile Phone Surface Based on Convolution Neural Network 

**论文摘要**：大规模的自动表面缺陷自动检测需要处理高分辨率图像并处理各种缺陷，同时要达到较高的准确率。 该研究提出了一种基于卷积神经网络（CNN）的缺陷检测方法。 首先，使用工业线性阵列相机获得手机的原始表面图像。 其次，通过建议的预处理步骤将获得的图像自动分割为指定的大小。 此外，我们在GoogLeNet网络的基础上设计了CNN，在不影响预测率的前提下，极大地减少了参数数量。 最后，对经过设计的CNN进行了培训和测试。 经过训练的CNN可以与滑动窗口技术结合使用，以检测原始图像中大小大于256×256分辨率的任何ROI。 实验结果表明，所设计的CNN的缺陷检测率可以达到99.5％。 

### [3] 论文题目：Defects Detection Based on Deep Learning and Transfer Learning 

论文摘要：缺陷检测是工业生产中重要的一步。通过对深度学习和迁移学习的研究，提出了一种基于深度学习和迁移学习的缺陷检测方法。我们的方法首先建立深度信任网络，并根据源域样本特征对其进行训练，以便根据源域样本获得网络的权重。然后，将源域DBN的结构和参数转移到目标域，并使用目标域样本对网络参数进行微调，以获得目标域训练样本与无缺陷模板之间的映射关系。最后，通过与重建图像进行比较，可以检测出测试样品的缺陷。这个方法不仅可以充分利用DBN的优势，还可以通过参数传递学习解决DBN网络训练中的过分烦恼。这些实验表明，DBN是成功的
高维特征空间信息提取任务中的一种方法，可以完美地建立映射关系，并可以快速，高精度地检测缺陷。 

## 2019.03

### [1]分割网络用于磁瓦缺陷检测

**论文题目**：Surface Defect Saliency of Magnetic Tile 

**论文摘要**：Vision-based detection on surface defects has long postulated in the magnetic tile automation process. In this work, we introduce a real-time and multi-module neural network model called MCuePush U-Net, specifically designed for the image saliency detection of magnetic tile. We show that the model exceeds the state-of-the-art, in which it both effectively and explicitly maps multiple surface defects from low-contrast images. Our model significantly reduces time cost of machinery from 0.5s per image to 0.07s, and enhances saliency accuracy on surface defect detection. 

### [2]经典的PHOT算法

**论文题目**：The Phase Only Transform for unsupervised surface defect detection 

**论文摘要**：我们提出了一种简单，快速，有效的方法来检测纹理表面上的缺陷。我们的方法是无监督的，不包含学习阶段或有关被检查纹理的信息。新方法基于仅相位变换（PHOT），该变换对应于离散傅立叶变换（DFT），并通过幅度进行了归一化。 PHOT从图像中删除任意比例的规则性，同时仅保留被认为代表缺陷的不规则图案。定位是通过逆变换，然后使用简单的标准统计方法进行自适应阈值确定的。因此，主要的计算要求是将DFT应用于输入图像。新方法也很容易在几行代码中实现。尽管方法简单，但在各种输入上进行测试时，这些方法仍然有效且通用，只需要一个参数即可实现灵敏度。我们提供基于简单模型的理论依据，并显示各种模式的结果。我们还将讨论一些限制。

### [3]经典的DCT算

**论文题目**：Tiny surface defect inspection of electronic passive components using discrete cosine transform decomposition and cumulative sum techniques 

**论文摘要**：无源组件由于其低功耗或无功耗而被广泛用于现代电子设备中。但是，经常出现在无源组件表面的微小缺陷不仅损害其外观，而且损害其功能。本文提出了一种全局方法，用于自动视觉检查SBL（表面阻挡层）芯片中的微小表面缺陷，该芯片的随机表面纹理不包含基本纹理基元的重复。提出的方法利用DCT分解和累加和技术，不需要纹理特征，而缺乏纹理特征通常会限制基于特征提取的方法的应用。我们将累积和算法应用于奇数奇数矩阵，该奇数奇数矩阵收集了分解后的DCT频域中的大多数功率谱，然后选择代表表面背景纹理的大幅度频率值。然后，通过在不选择频率值的情况下重建频率矩阵，我们消除了随机纹理图案，并在恢复的图像中保留了异常。实验结果证明了该方法在检查随机纹理中的微小缺陷方面的有效性。

## 2019.04

### [1]论文题目：Anomaly Detection in Nanofibrous Materials by CNN-Based Self-Similarity 

**论文摘要**：纳米纤维材料中异常的自动检测和定位有助于减少生产过程的成本和生产后视觉检查过程的时间。 在所有监测方法中，利用扫描电子显微镜（SEM）成像的方法最为有效。 在本文中，我们基于卷积神经网络（CNN）和自相似性，提出了一种基于区域的SEM图像异常检测和定位方法。 该方法通过计算关于属于训练集的无异常子区域的字典的基于CNN的视觉相似度，来评估所考虑图像的每个子区域的异常程度。 所提出的方法优于现有技术。

**个人总结**：详细的分析见：https://blog.csdn.net/qq_27871973/article/details/86007150

### [2]论文题目：Automatic Defect Detection of Fasteners on theCatenary Support Device Using Deep
Convolutional Neural Network 

**摘要**：由铁路车辆的长期运行引起的激励和振动不可避免地导致悬链线支撑装置的故障状态。随着高速电气化铁路的大规模建设，在悬链线支撑装置上自动检测多种多样的紧固件的缺陷对运营安全和降低成本具有重要意义。如今，在夜间，安装在检查车辆上的摄像机会定期捕获接触网支撑设备，但检查仍主要依靠人类的视觉解释。为了减少人员的参与，本文提出了一种新颖的基于视觉的方法，该方法将深度卷积神经网络（DCNN）应用到紧固件的缺陷检测中。我们的系统从粗到细地级联了三个基于DCNN的检测阶段，包括两个检测器以顺序定位悬臂接头及其紧固件，以及一个分类器以诊断紧固件的缺陷。武广高铁沿线接触网支撑装置缺陷检测的大量实验和比较表明，该系统在复杂环境下可以达到较高的检测率，具有良好的适应性和鲁棒性。

**个人总结**：2018年2月的一篇杂志论文。作者将深度卷积神经网络(DCNNs)应用到高铁线路紧固件缺陷检测。结合SSD、YOLO等网络方法构建了一个从粗到细的级联检测网络，包括：两个检测器对悬臂节点及其紧固件进行定位，一个分类器对紧固件缺陷进行分类。特别是实验部分，作者做的很充分。

### [3]论文题目：Automatic Fabric Defect Detection with a Multi-Scale Convolutional Denoising Autoencoder Network Model 

**摘要**：织物缺陷检测是纺织品制造业中质量控制的必要和必不可少的步骤。传统的织物检查通常是通过人工视觉方法进行的，对于长期的工业应用而言，这种方法效率低下且精度较差。在本文中，我们提出了一种无监督的基于学习的自动化方法，无需任何人工干预即可检测和定位织物缺陷。该方法用于在多个高斯金字塔等级上通过卷积去噪自动编码器网络重建图像斑块，并合成来自相应分辨率通道的检测结果。每个图像块的重建残差用作直接逐像素预测的指示符。通过分割和合成每个分辨率级别的重建残差图，可以生成最终检查结果。这种新开发的方法在织物缺陷检测方面具有几个突出的优势。首先，仅需少量的无缺陷样本即可对其进行训练。这对于收集大量有缺陷的样品既困难又不切实际的情况尤为重要。其次，由于采用了多模式集成策略，与常规检查方法相比，它相对更健壮和准确（每个分辨率级别的结果都可以视为一种模式）。第三，根据我们的结果，它可以处理多种类型的纺织品，从简单到更复杂。实验结果表明，所提出的模型是鲁棒的，并具有良好的整体性能，具有很高的精度和可接受的召回率。

**个人总结**：核心思路同2019.01的第二篇。

## 2019.05

### [1]CNN做分类

**论文题目**：Design of deep convolutional neural network architectures for automated feature extraction in industrial inspection 

**论文摘要**：Fast and reliable industrial inspection is a main challenge in manufacturing scenarios. However, the defect
detection performance is heavily dependent on manually defined features for defect representation. In
this contribution, we investigate a new paradigm from machine learning, namely deep machine learning
by examining design configurations of deep Convolutional Neural Networks (CNN) and the impact of
different hyper-parameter settings towards the accuracy of defect detection results. In contrast to
manually designed image processing solutions, deep CNN automatically generate powerful features by
hierarchical learning strategies from massive amounts of training data with a minimum of human
interaction or expert process knowledge. An application of the proposed method demonstrates excellent
defect detection results with low false alarm rates. 

### [2]论文题目：Non-parametric texture defect detection using Weibull features 

**论文摘要**：The detection of abnormalities is a very challenging problem in computer vision, especially if these abnormalities must be detected in images of textured surfaces such as textile, stone, or wood. We propose a novel, nonparametric approach for defect detection in textures that only employs two features. We compute the two parameters of a Weibull fit for the distribution of image gradients in local regions. Then, we perform a simple novelty detection algorithm in order to detect arbitrary deviations of the reference texture. Therefore, we evaluate the Euclidean distances of all local patches to a reference point in the Weibull space, where the reference point is determined for each texture image individually. Thus, our approach becomes independent of the particular texture type and also independent of a certain defect type.
For performance evaluation we use the highly challenging database provided by Bosch for a contest on
industrial optical inspection with different classes of textures and different defect types. By using the Weibull parameters we can detect local deviations of texture images in an unsupervised manner with high accuracy. Compared to existing approaches such as Gabor filters or grey level statistics, our approach is not only powerful, but also very efficient such that it can also be applied for real-time applications. 

### [3]论文题目：Learning Defect Classifiers for Visual Inspection Images by Neuro-Evolution using Weakly Labelled Training Data

**论文摘要**： This article presents results from experiments where a detector for defects in visual inspection images was learned from scratch by EANT2, a method for evolutionary reinforcement learning. The detector is constructed as a neural network that takes as input statistical data on filter responses
from a bank of image filters applied to an image region. Training is done on example images with weakly labelled defects. Experiments show good results of EANT2 in an application area where evolutionary methods are rare. 

## 2019.06

### [1]GAN用于缺陷检测

论文题目：A Surface Defect Detection Method Based on Positive Samples 

**论文摘要**：Surface defect detection and classification based on machine vision can greatly improve the efficiency of industrial production. With enough labeled images, defect detection methods based on convolution neural network have achieved the detection effect of state-of-art. However in practical applications, the defect samples or negative samples are usually difficult to be collected before‐
hand and manual labelling is time-consuming. In this paper, a novel defect detection framework only based on training of positive samples is proposed. The basic detection concept is to establish a reconstruction network which can repair defect areas in the samples if they are existed, and then make a comparison between the input sample and the restored one to indicate the accurate defect areas. We combine GAN and autoencoder for defect image reconstruction and use LBP for image local contrast to detect defects. In the training process of the algorithm, only positive samples is needed, without defect samples and manual label. This paper carries out verification experiments for concentrated fabric images and the dataset of DAGM 2007. Experiments show that the proposed GAN+LBP algorithm and supervised training algorithm with sufficient training samples have fairly high detection accuracy. Because of its unsupervised characteristics, it has higher practical application value. 

**个人总结**：详细分析 https://blog.csdn.net/qq_27871973/article/details/84068984

### [2]论文题目：GANomaly: Semi-Supervised Anomaly Detection via Adversarial Training  

**论文摘要**：Anomaly detection is a classical problem in computer vision, namely the determination of the normal from the abnormal when datasets are highly biased towards one class (normal) due to the insufficient sample size of the other class (abnormal). While this can be addressed as a supervised learning problem, a significantly more challenging problem is that of detecting the unknown/unseen anomaly case that takes us instead into the space of a one-class, semi-supervised learning paradigm. We introduce such a novel anomaly detection model, by using a conditional generative adversarial network that jointly learns the generation of high-dimensional image space and the inference of latent space. Employing encoder-decoder-encoder sub-networks in the generator network enables the model to map the input image to a lower dimension vector, which is then used to reconstruct the generated output image. The use of the additional encoder network maps this generated image to its latent representation. Minimizing the distance between these images and the latent vectors during training aids in learning the data distribution for the normal samples. As a result, a larger distance metric from this learned data distribution at inference time is indicative of an outlier from that distribution | an anomaly. Experimentation over several benchmark datasets, from varying domains, shows the model efficacy and superiority over previous state-of-the-art approaches. 

### [3]GAN用于缺陷分类

**论文题目**：Surface defect classification of steels with a new semi-supervised learning method 

**论文摘要**：Defect inspection is extremely crucial to ensure the quality of steel surface. It affects not only the subsequent production, but also the quality of the end-products. However, due to the rare occurrence and appearance variations of defects, surface defect identification of steels has always been a challenging task. Recently, deep learning methods have shown outstanding performance in image classification, especially when there are enough training samples. Since most sample images of steel surface are unlabeled, a new semi-supervised learning method is proposed to classify surface defects of steels. The new method is named CAE-SGAN, as it is based on Convolutional Autoencoder (CAE) and semi-supervised Generative Adversarial Networks (SGAN). CAE-SGAN first trains a stacked CAE through massive unlabeled data. Considering the appearance variations of defects, the passthrough layer is used to help CAE extract fine-grained features. After CAE is trained, the encoder network of CAE is reserved as the feature extractor and fed into a softmax layer to form a new classifier. SGAN is introduced for semi-supervised learning to further improve the generalization ability of the new method. The classifier is trained with images collected from real production lines and images randomly generated by SGAN. Extensive experiments are carried out with samples captured from different steel production lines, and the results indicate that CAESGAN had yielded best performances compared with traditional methods. Especially for hot rolled plates, the classification rate is improved by around 16%. 

### [4]YOLO用于缺陷检测

**论文题目**：Real-time Detection of Steel Strip Surface Defects Based on Improved YOLO Detection Network

**论文摘要**：The surface defects of steel strip have diverse and complex features, and surface
defects caused by different production lines tend to have different characteristics. Therefore,
the detection algorithms for the surface defects of steel strip should have good generalization
performance. Aiming at detecting surface defects of steel strip, we established a dataset of six
types of surface defects on cold-rolled steel strip and augmented it in order to reduce over-fitting.
We improved the You Only Look Once (YOLO) network and made it all convolutional. Our improved network, which consists of 27 convolution layers, provides an end-to-end solution for the surface defects detection of steel strip. We evaluated the six types of defects with our network
and reached performance of 97.55% mAP and 95.86% recall rate. Besides, our network achieves
99% detection rate with speed of 83 FPS, which provides methodological support for real-time
surface defects detection of steel strip. It can also predict the location and size information of
defect regions,  which is of great significance for evaluating the quality of an entire steel strip
production line.

## 2019.10

### [1]半监督方法的异常检测

论文题目：A semi-supervised convolutional neural network-based method for steel

Automatic defect recognition is one of the research hotspots in steel production, but most of the current methods focus on supervised learning, which relies on large-scale labeled samples. In some real-world cases, it is difcult to collect and label enough samples for model training, and this might impede the application of most current works. The semi-supervised learning, using both labeled and unlabeled samples for model training, can overcome this problem well. In this paper, a semi-supervised learning method using the convolutional neural network (CNN) is proposed for steel surface defect recognition. The proposed method requires fewer labeled samples, and the unlabeled data can be used to help training. And, the CNN is improved by Pseudo-Label. The experimental results on a benchmark dataset of steel surface defect recognition indicate that the proposed method can achieve good performances with limited labeled data, which achieves an accuracy of 90.7% with 17.53% improvement. Furthermore, the proposed method has been applied to a real-world case from a Chinese steel company, and obtains an accuracy of 86.72% which signifcantly better than the original method in this workshop. 

### [2]小样本下用语义分割方法做检测

论文题目：Segmentation-based deep-learning approach for surface-defect detection

Automated surface-anomaly detection using machine learning has become an interesting and promising area of research, with a very high and direct impact on the application domain of visual inspection. Deep-learning methods have become the most suitable approaches for this task. They allow the inspection system to learn to detect the surface anomaly by simply showing it a number of exemplar images. This paper presents a segmentation-based deep-learning architecture that is designed for the detection and segmentation of surface anomalies and is demonstrated on a specific domain of surface-crack detection. The design of the architecture enables the model to be trained using a small number of samples, which is an important requirement for practical applications. The proposed model is compared with the related deep-learning methods, including the state-ofthe-art commercial software, showing that the proposed approach outperforms the related methods on the specific domain of surface-crack detection. The large number of experiments also shed light on the required precision of the annotation, the number of required training samples and on the required computational cost. Experiments are performed on a newly created dataset based on a real-world quality control case and demonstrates that the proposed approach is able to
learn on a small number of defected surfaces, using only approximately 25-30 defective training samples, instead of hundreds or thousands, which is usually the case in deeplearning applications. This makes the deep-learning method practical for use in industry where the number of available defective samples is limited. The dataset is also made publicly available to encourage the development and evaluation of new methods for surface-defect detection. 

### [3]SDD-CNN用于检测

论文题目：SDD-CNN: Small Data-Driven Convolution Neural Networks for Subtle Roller Defect Inspection 

Roller bearings are some of the most critical and widely used components in rotating machinery. Appearance defect inspection plays a key role in bearing quality control. However, in real industries, bearing defects are usually extremely subtle and have a low probability of occurrence. This leads to distribution discrepancies between the number of positive and negative samples, which makes intelligent data-driven inspection methods difficult to develop and deploy. This paper presents a small data-driven convolution neural network (SDD-CNN) for roller subtle defect inspection via an ensemble method for small data preprocessing. First, label dilation (LD) is applied to solve the problem of an imbalance in class distribution. Second, a semi-supervised data augmentation (SSDA) method is proposed to extend the dataset in a more efficient and controlled way. In this method, a coarse CNN model is trained to generate ground truth class activation and guide the random cropping of images. Third, four variants of the CNN model, namely, SqueezeNet v1.1, Inception v3, VGG-16, and ResNet-18, are introduced and employed to inspect and classify the surface defects of rollers. Finally, a rich set of experiments and assessments is conducted, indicating that these SDD-CNN models, particularly the SDD-Inception v3 model, perform exceedingly well in the roller defect classification task with a top-1 accuracy reaching 99.56%. In addition, the convergence time and classification accuracy for an SDD-CNN model achieve significant improvement compared to that for the original CNN. Overall, using an SDD-CNN architecture, this paper provides a clear path toward a higher precision and efficiency for roller defect inspection in smart manufacturing. 

## 2019.11

### [1] FCN用于缺陷检测，以前也有人搞过，这篇有创新。

论文题目：A High-Efficiency Fully Convolutional Networks for Pixel-Wise Surface Defect Detection

In this paper, we propose a highly efficient deep learning-based method for pixel-wise surface
defect segmentation algorithm in machine vision. Our method is composed of a segmentation stage (stage
1), a detection stage (stage 2), and a matting stage (stage 3). In the segmentation stage, a lightweight
fully convolutional network (FCN) is employed to make a pixel-wise prediction of the defect areas. Those
predicted defect areas act as the initialization of stage 2, guiding the process of detection to correct the
improper segmentation. In the matting stage, a guided filter is utilized to refine the contour of the defect
area to reflect the real abnormal region. Besides that, aiming to achieve the tradeoff between efficiency and
accuracy, and simultaneously we use depthwise&pointwise convolution layer, strided depthwise convolution layer, and upsample depthwise convolution layer to replace the standard convolution layer, pooling layer, and deconvolution layer, respectively. We validate our findings by analyzing the performance obtained on the dataset of DAGM 2007. 

### [2] 又一篇比较不错的GAN网络做表面异常检测，值得细看哈！

题目：Unsupervised fabric defect detection based on a deep convolutional generative adversarial network

Detecting and locating surface defects in textured materials is a crucial but challenging problem due to factors such as texture variations and lack of adequate defective samples prior to testing. In this paper we present a novel unsupervised method for automatically detecting defects in fabrics based on a deep convolutional generative adversarial network (DCGAN). The proposed method extends the standard DCGAN, which consists of a discriminator and a generator, by introducing a new encoder component. With the assistance of this encoder, our model can reconstruct a given query image such that no defects but only normal textures will be preserved in the reconstruction. Therefore, when subtracting the reconstruction from the original image, a residual map can be created to highlight potential defective regions. Besides, our model generates a likelihood map for the image under inspection where each pixel value indicates the probability of occurrence of defects at that location. The residual map and the likelihood map are then synthesized together to form an enhanced fusion map. Typically, the fusion map exhibits uniform gray levels over defect-free regions but distinct deviations over defective areas, which can be further thresholded to produce a binarized segmentation result. Our model can be unsupervisedly trained by feeding with a set of small-sized image patches picked from a few defect-free examples. The training is divided into several successively performed stages, each under an individual training strategy. The performance of the proposed method has been extensively evaluated by a variety of real fabric samples.
The experimental results in comparison with other methods demonstrate its effectiveness in fabric defect detection. 

<br>

:email: yidazhang1@gmail.com

