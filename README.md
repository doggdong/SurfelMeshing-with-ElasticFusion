## 介绍

**elastic fusion**与**surfel meshing**结合，前者算相机位姿，后者建图，在无轨迹文件的情况下，实时计算位姿并在线稠密重建

-----



## 使用方法

1. 配置环境

   * [ElasticFusion](https://github.com/mp3guy/ElasticFusion)和[Surfelmeshing](https://github.com/puzzlepaint/surfelmeshing)源码都编译通过即可

2. 下载tum数据集

   1. 下载地址 [TUM RGB-D benchmark](https://vision.in.tum.de/data/datasets/rgbd-dataset) 

   2. 进入数据集文件夹新建 `calibration.txt` 文件，内容为：

      ```
      525.0 525.0 319.5 239.5
      ```

   3. 运行如下命令，生成`associated.txt` 文件

      ```
      python associate.py rgb.txt depth.txt > associated.txt
      ```

      

3. 编译运行

   ```
   mkdir build && cd build
   cmake ..
   make 
   ./applications/surfel_meshing/SurfelMeshing “数据集路径”
   ```

-----



