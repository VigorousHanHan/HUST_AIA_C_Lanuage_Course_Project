#### 基本说明
我们小组两人分别是X和Y。该仓库下文件基本和老师发的文件夹一致，只是修改了dosbox文件夹中bc31.conf的部分配置。详细修改方法可以查看B站学长六个钢镚的教学视频。我们自己写的代码都保存在DISK_C/CODE文件夹中，因此接下来重点介绍这个文件夹。
#### CODE文件夹简介
##### HEADER
这个文件夹用于储存头文件，与SOURCE中的.c文件对应。
##### HZK
这个文件夹是学长写的汉字库。如果要使用汉字库，那么你写的C语言代码都要使用GBK保存，不能使用UTF-8，否则会出现乱码。
##### OUTPUT
这个文件夹用于存放BC的输出文件。
##### SOURCE
这个文件夹用于存放我们写的代码。许多菜单的子页面只是用来水代码的，只是一些绘制了一些界面，并没有什么实际功能或者算法。(。??︿??。)
###### ac.c
aircondition的缩写，表示空调界面，菜单的子界面。
###### battery.c
绘制电池界面，菜单的子界面。
###### display.c
绘制显示界面，能够展示时间、电量等信息。点击启动按钮后，可以根据导航中寻找的路径模拟自动行驶到目的地，同时显示行驶状态、车速、位置等信息。行驶过程中可能出现障碍物需要手动操作。
###### door.c
绘制车门界面，菜单的子界面。
###### drive.c
绘制驾驶界面，菜单的子界面。
###### hz.c
学长写的汉字库函数，具体用法可以查看B站学长六个钢镚的教学视频。如果出现Can't open xxx file!Press any key to quit...字样，可以查看该文件中的xxx文件路径与HZK中xxx文件的路径是否相同，建议使用相对路径，如果使用绝对路径可能会和机房电脑上的路径不同，需要重新修改相关内容。此外，存储汉字一定要用数组，不要使用指针，否则会出现内存泄漏，具体表现就是程序运行一段时间后汉字乱码，有时还会闪退。
###### init.c
存储初始化相关函数和多个界面都需要调用的函数。
###### light.c
绘制灯光界面，菜单的子界面。
###### main.c
主函数。
###### map.c
绘制地图的界面。
###### menu.c
绘制菜单界面。
###### mouse.c
学长写的鼠标库函数，具体用法可以查看B站学长六个钢镚的教学视频。
###### navigation.c
绘制导航界面。
###### normal.c
绘制显示界面在正常行驶过程的界面，对应的绘制异常行驶过程的界面的函数被放在display.c中，并没有单独创建一个abnormal.c来储存。
###### page.c
绘制主界面（就是一打开就显示的那个界面）。右下方的空白最开始是打算留给娱乐功能的按钮的，不过后来没时间了，也就没写了。
###### plan.c
导航类函数，使用Dijkstra算法寻找、储存并绘制最短路径。
###### sunroof.c
绘制天窗界面，菜单的子界面。
###### tire.c
绘制胎压界面，菜单的子界面。
###### window.c
绘制车窗界面，菜单的子界面。
###### wiper.c
绘制雨刷界面，菜单的子界面。
##### pic
这个文件夹下存放了一张图片，里面标注了每个地点或路口的标号。Plan.c中有一个名为distance的34*34的矩阵，用于存储地图中相邻两点的距离，其行或列数字对应的地点或路口，就是图片中标号标注的地点或路口。
##### text
这个文件夹下用于存放.txt文件。这些文本文件中存放的都是汽车的状态信息，例如battery.txt中汽车的电量（0-100）、light.txt中灯的开关状态（0或1）、window,txt中车窗打开的大小（0-10），并且除path.txt外都在SOURCE中有对应文件。
对于这些文本文件，只有对应的.c文件会读取它，并且一般都是在.c文件中的第一个函数开头的fscanf处读取，并且用一个名为num的数组保存，最后再在该函数结尾处的fprintf保存修改后的值。观察一下每个参数是在哪里用到，就能知道每个参数是储存什么的。
对于path.txt，这个文本是用于存放路径的，第奇数个数字表示地点（数字和地点的对应关系见pic中的图片），第偶数个数字代表它前一个数字和后一个数字所对应的地点之间的距离。例如，2 50 15 100 14 25 1，这段数字表示从图书馆到科技楼南楼的一条路径，其中2（图书馆），15（路口），14（路口），1（科技楼南楼）代表地点，50，100，25，表示距离，分别代表2和15之间距离为50米，，15和14之间距离为100米，14和1之间距离为25米。plan.c中的Dijkstra函数会将寻找到的最短路径存储到该文本中，DrawRoute函数会读取其中的值并将该路径显示在地图中。
此外，其他一些文件也会读取或修改这些文本的值。例如，display.c会读取path.txt中的值，用于在行驶过程中模拟导航过程；还会读取并修改battery.txt的值，用于显示行驶过程中的实时电量。
##### TEXT.PRJ && TEXT.DSK
这两个就是BC的工程文件。起初命名是test，表示是测试用的，但是不知道为什么跑不了了，只好重新创建新的工程，就随便取了个名叫TEXT。╮(︶﹏︶)╭
#### 验收过程
我们是最后一天晚上何顶新老师验收的。助教看代码量的时候是直接用VScode的插件给的数，也就是说除了空行外都算代码行数，即使这一行只有一个“{”。何顶新老师并没有细看我们的程序，直接问我们：“你觉得你们这个程序最出色的地方是什么？”然后我们就展示了一下导航功能。我们那个导航功能是只能输入起点和终点进行导航，他就让我们给导航功能增加一个可以实现添加途径点的功能，然后就去验收另一组了。我们大概花了四十五分钟左右添加完功能，整个过程除了一开始他去验收另一组的时候在机房里，其他时间都消失了（可能吃饭去了？），最后还是另一组找他们研班才把老师找回来。因为花的时间比较长，老师说他相信我们是完成了这个功能的，也就没有检查，直接给我们两个人打B和C。另一组也是要求加同样的功能，只花了十分钟左右吧，老师验收完后给了A。而且他们也是非常厉害的，写的程序的部分功能用机房的原生BC带不动，最后还是在笔记本上用虚拟机展示的。
#### 总结
这个程序可能不是非常出色，创建这个仓库也只是打算记录一下自己写课设的过程和经验，也希望能够帮助到后来的同学吧。
