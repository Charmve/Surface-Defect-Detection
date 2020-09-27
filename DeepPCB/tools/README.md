# PCB Annotation Tool
This is the annotation tool for efficiently annotating PCB defect on the tested images. You can add annotation of existed defects or manually create new defect with the help of this tool.
<div align=center><img src="https://github.com/tangsanli5201/DeepPCB/blob/master/fig/tools/PCBAnnotationSoftware.png" width="800" style="margin:20"></div>
## Environment
Qt 5.4.1
Windows 10

## Installation
You can install this software from the source codes easily:
1. download this project.
2. open the file **_./tools/PCBAnnotationTool/PCBAnnotationTool.pro_** by **QtCreator** 
3. in the **project** bar of **QtCreator**, set the **_ build directory_** to the directory: **_./tools_**
3. build (Ctrl+R) this project.

## Examples
1. Edit the filelist: **_./tools/examples/test.txt_** and set the input image path and output annotation file path.

2. build (Ctrl+R) this project in the **QtCreator**

3. click **open** button and open the filelist **_./tools/examples/test.txt_**

4. double click any line on the left table to open an image to be annotated. If you are first annotating this image, a warning message will occur to inform you that it cannot find the existing annotation file (since this is your first annotation for this image). And a new annotation file will be created according to the path you set in the filelist on the first step.

5-1 (optional) manually add a new defect: click one of the button in the toolbar: **open, short, mousebite, spur, copper, pinhole**, and draw a corresponding defect on the **tested image** window. A bounding box will be automatically generated. Click **save** button when you finish drawing current defect.

5-2 (optional) annotate an exsisting defect: click one of the button in the boolbar which is named the same type as the one you want to annotate. click several point on the bounding of the defect to generate a bounding box. Click **save** button when you finish annotating current defect.

5-3 (optional) delete a annotation: select the line to be deteted on the left table. Select on the menu: **tools**->**delete**. An click **save** button on the toolbar to save the delete operation. **Notice**: the delete operation will only delete the annotation record, but it will **NOT DO ANY REVISION** on the tested image.

6. click the **return** button on the toolbar to finish annotating the current image. A annotation file will be generated according to the path you set on the first step.