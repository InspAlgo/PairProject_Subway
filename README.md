！！！The project has stopped development and maintenance.  
===  
# PairProject_Subway
结对项目-地铁项目  
个人博客：[InspAlgo](https://blog.csdn.net/qq_38597315)  
结对项目博客：[软件工程基础课-结对项目-地铁](https://blog.csdn.net/qq_38597315/article/details/80224637)  
结对项目纪实：[软件工程基础课-结对项目纪实](https://blog.csdn.net/qq_38597315/article/details/80229197)

v1.1.1：[Beijing Subway](https://github.com/InspAlgo/PairProject_Subway/releases)
***

## 一、文件说明
1. Project_Subway_Console文件夹
这里存放的是纯控制台程序的代码（C++），目前支持的参数有`/a`、`/b`、`/c`、`/d`、`/z` 。

2. DLLCS文件夹
这里存放的是动态依赖库代码，代码主体基于之前的控制台的程序，将其封装以便界面程序调用。目前开放的调用函数有`ConsoleInterface()`和`GUIInterface()`前者是将结果输出到控制台，后者是将结果输出到文本`gui_print.txt`。使用`console_input.txt`文本传入参数，文本中的数据格式见下。

```
/a
郭公庄
```
```
/b 
知春路
中关村
```
```
/c
1号线
```
```
/d
知春路
中关村
```
```
/s
郭公庄
```

3. CS_Project_Console文件夹
这里存放的是由C#编写的控制台程序，同时可以加载界面。目前支持的参数有`/a`、`/b`、`/c`、`/d`、`/z` 。

4. subway_console.exe
使用C++编写的Win10 x64纯控制台应用程序。

5. DLLCS.dll
使用C++编写的Win10 x64动态依赖库程序。仅供subway_gui.exe调用使用。

6. subway_gui.exe 
使用C#编写的Win10 x64控制台应用程序，使用`/g`参数可调出界面端。

7. beijing-subway.txt
存放北京地铁数据的文本文件。

8. console_input.txt
由subway_gui.exe生成，里面储存的是界面传入依赖库参数的信息，由于生成后不会自动删除，所以正常忽略即可，再次生成时如果不删则覆盖写入。

9. gui_print.txt
由DLLCS.dll生成，里面储存的是依赖库生成的路径各站点的坐标，由于生成后不会自动删除，所以正常忽略即可，再次生成时如果不删则覆盖写入。

10. beijing_subway_traverse.txt
由subway_console.exe或DLLCS.dll生成，里面储存的是`/a`参数下的遍历输出结果。其在`/z`参数下被取读检查结果正确性。

***

## 二、参数说明
1. `/a`参数
如输入`/a 郭公庄`，从`郭公庄`出发遍历所有站点并最终返回起点`郭公庄`。运行结束后将会生成名为`beijing_subway_traverse.txt`文本文件，生成的结果将保存其中，显示的是依次走过的站点。

2. `/b`参数
如输入`/b 郭公庄 魏公村`，从起点`郭公庄`出发以最短路径到达终点`魏公村`，此最短路径是以经过最少站点为标准，当存在多条最短路径时会输出第一次得到的最短路径。运行结果将打印在控制台界面。
此用例的输出结果样式为：
```
14
郭公庄
丰台科技园
科怡路
丰台南路
丰台东大街
七里庄
六里桥 换乘10号线
莲花桥
公主坟 换乘1号线
军事博物馆 换乘9号线
白堆子
白石桥南
国家图书馆 换乘4号线/大兴线
魏公村
```

3. `/c`参数
如输入`/c 1号线`，将依次在控制台界面打印出此地铁1号线经过的所有站点。
此用例的输出结果样式为：
```
1号线
苹果园
古城
八角游乐园
八宝山
玉泉路
五棵松
万寿路
公主坟
军事博物馆
木樨地
南礼士路
复兴门
西单
天安门西
天安门东
王府井
东单
建国门
永安里
国贸
大望路
四惠
四惠东
```

4. `/d`参数
如输入`/d 郭公庄 魏公村`，从起点`郭公庄`出发并以相对于`/b`参数下较少换乘次数到达终点`魏公村`。
此用例的输出结果样式为：
```
14
郭公庄
丰台科技园
科怡路
丰台南路
丰台东大街
七里庄
六里桥
六里桥东
北京西站
军事博物馆
白堆子
白石桥南
国家图书馆 换乘4号线/大兴线
魏公村
```

5. `/z`参数
如输入`/z beijing_subway_traverse.txt`将会检查/a参数的输出结果，输出结果打印在控制台。输出结果有`True`、`False`、`Error`三种，当输出的结果确实遍历到了所有站点，无遗漏，且相邻两站点可直达则结果正确输出`true`，如果有遗漏站点则输出`false`同时输出遗漏站点名称，如果两相邻站点实际不可直达（郭公庄到魏公村就是不可直达的，需要经过其他站点）则输出`error`，同时输出这两个错误的站点名称。

6. `/g`参数
仅限`subway_gui.exe`程序使用，但输入`/g`后即可调出界面。

7. `/s`参数
此参数不对用户开放，仅由subway_gui.exe自行传入DLLCS.dll中使用。此参数对应界面端的`站点显示`功能，由subway_gui.exe写到console_input.txt中，格式如下：
```
/s
郭公庄
```
由DLLCS.dll接收后输出`郭公庄`的界面上的坐标信息并存于gui_print.txt中供subway_gui.exe使用。

***

## 三、特殊的站及线路
首先输入的站点名和地铁线名以`beijing-subway.txt`中出现的站点名和地铁线名为准。

需要特别注意的站点名称有`2号航站楼`、`3号航站楼`。

S1线在实际地图上与1号线不相连，即`金安桥`站和`苹果园`站之间无地铁，但本程序为了方便起见将这两个站点之间算S1线。部分未开通的站点也同理当作已开通。

4号线和大兴线由于不好具体区分，所以合称`4号线/大兴线`。

14号线分`14号线东线`、`14号线西线`。

由于文本数据设计原因，`四惠`站和`四惠东`站之间只算属于`八通线`，但`单独`打印`1号线`时任包括`四惠东`站。

***
