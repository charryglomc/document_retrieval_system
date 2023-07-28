# document_retrieval_system

> 为了熟悉并掌握搜索引擎的整个流程和进一步巩固c++的学习，基于Linux平台，设计了一个轻量级的文档检索系统，该系统服务器端基于`Linux` 平台、C/C++语言；客户端采用PHP实现；爬虫采用Python实现。


### 项目简介

该项目是一个用于网页查询的轻量级搜索引擎。实现了从`爬取网页`，`处理网页`，`显示结果`等整个搜索引擎的流程。该项目分为两个个阶段：**线下阶段**，**线上阶段**。**线下阶段**使用`tinyxml2`解析爬取的网页，以此建立`网页库`，网页`偏移库`；使用`cppjieba`进行中文分词，使用`SimHash算法库 `进行网页去重并生成新的`网页库`与`网页偏移库`，去重后通过`TF-IDF算法`建立`倒排索引`。**线上阶段**则采用了Reactor + 线程池的网络库，客户端发送查询词后，服务器计算文本特征并建立`VSM模型`，并使用`余弦相似度算法`匹配网页，将匹配的网页通过`余弦值`排序后使用`jsoncpp`封装后发送给前端，本项目使用`redis`作为`Cache缓存`，`log4cpp`添加`日志系统`。

<br>


### 项目详细流程
该项目主要分为三个阶段：**线下阶段**，**线上阶段**，**优化阶段**。


* **线下阶段**

  1. 首先使用**tinyxml2**解析python爬取的网页，将爬取的网页进行进行解析之后放入内存，再将内存中的网页**整理格式**之后，输出到磁盘，这也就时创建 **网页库** 与 **网页偏移库** 的过程。


  2. 读取网页库与网页偏移库，使用 **cppjieba库** 对文章进行分词，再使用 **针对中文文档的SimHash算法库** 对文章进行去重。根据去重之后的文章，建立 **新的网页库** 与 **新的网页偏移库**。

  3. 使用 **TF-IDF** 算法建立 **倒排索引库**。


* **线上阶段**：采用Reactor + 线程池的网络库，服务端具体处理流程如下：
1.  将客户端发送的查询语句**看成一篇文章**，通过**TF-IDF**算法计算出各个单词在该篇文章中的权重。


    2. 通过**倒排索引**，查找出**所有匹配的网页**。这里的匹配代表着该网页中包含客户端查询词中的所有关键词。

    3. 使用 **余弦相似度算法** 计算出每一篇网页对应查询语句的余弦相似度，根据余弦相似度大小对网页进行排序。

    4. 为每一篇网页都形成**摘要**。

    5. 将文章封装成**json字符串**返回给客户端。

    6. 客户端**解析json**字符串并显示。

    7. 使用Redis作为Cache缓存。

8. 使用**log4cpp**记录日志文件。

<br>

### 用法及演示

- Redis配置

```shell
sudo apt install redis-server
git clone git@github.com:redis/hiredis.git
cd hiredis
make
./test.sh
sudo make install
```

- 离线部分

```shell
cd offline
make
./offline.exe
```

- 线上部分

```shell
cd ..
make
./server.exe
```

- 前端搭建

```shell
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install apache2
sudo apt-get install php7.2 libapache2-mod-php7.2
sudo cp php_TCP /var/www/html/
```

在浏览器中输入http://127.0.0.1/php_TCP/index.html

<br>


### 系统运行过程图

<img src="https://s2.loli.net/2023/07/18/X6glyFtVNmfJ1Ti.png" alt="image.png" style="zoom:50%;" />

