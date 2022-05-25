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

3. 链接ElasticFusion与SurfelMeshing项目

   1. 进入ElasticFusion项目中Core文件 `"ElaticFuison path"/Elastic/code/ElasticFusion/Core/build`

   2. 执行`sudo make install`

   3. 找到本项目中的Findfusion.cmake文件 `"your path"/surfelmeshing/cmake`

   4. 将以下两行代表寻找ElasticFusion的Core接口，在这两行下**添加**你ElasticFusion Core文件下的的build文件位置即可

      ```
      #  ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/build
      #  ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/src/build
      ```

      比如我的位置是`/home/dog/Documents/article/Elastic/code/ElasticFusion1/Core/build`

      ```
      find_library(EFUSION_LIBRARY
                   NAMES libefusion.so
                   PATHS
                    #  ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/build
                    #  ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/src/build
                    /home/dog/Documents/article/Elastic/code/ElasticFusion1/Core/build
                   PATH_SUFFIXES ${EFUSION_PATH_SUFFIXES}
      )
      
      ```

      

      

4. 编译运行

   ```
   mkdir build && cd build
   cmake ..
   make 
   ./applications/surfel_meshing/SurfelMeshing “数据集路径”
   ```

-----



