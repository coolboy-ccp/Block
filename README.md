# 简单说说Block

## [语法](http://fuckingblocksyntax.com)

## [结构](/BlockStruct.h)
## isa指向
* [oc](/TestBlock.m)
* [cpp](/TestBlock..cpp)
* 在block是对象，所以这个aBlock默认是有__strong修饰符的，即aBlock对该block有strong references。即aBlock在被赋值的那一刻，这个block会被copy。所以，ARC开启后，所能接触到的block基本都是在堆上的。。
## block对变量的捕获规则
*  静态存储区的变量：例如全局变量、方法中的static变量
引用，可修改。

* block接受的参数
传值，可修改，和一般函数的参数相同。

* 栈变量 (被捕获的上下文变量)
const，不可修改。 当block被copy后，block会对 id类型的变量产生强引用。
每次执行block时,捕获到的变量都是最初的值。

* 栈变量 (有__block前缀)
引用，可以修改。如果时id类型则不会被block retain,必须手动处理其内存管理。
如果该类型是C类型变量，block被copy到heap后,该值也会被挪动到heap
## 循环引用
### reason
当block被copy之后(如开启了ARC、或把block放入dispatch queue)，该block对它捕获的对象产生strong references (非ARC下是retain),
所以有时需要避免block copy后产生的循环引用。
如果用self引用了block，block又捕获了self，这样就会有循环引用。
### 解决
* __weak修饰
* 定义全局block(目的就是让self不强引用block)

## __block
默认block捕获到的变量，都是赋值给block的结构体的，相当于const不可改。为了让block能访问并修改外部变量，需要加上__block修饰词。[oc]()[cpp]()
__block会将被修饰的值的位置变成了一个struct（struct __Block_byref）。这个struct的首地址为同样为*isa。
正是如此，这个值才能被block共享、并且不受栈帧生命周期的限制、在block被copy后，能够随着block复制到堆上。
## block内部修改外部变量的方法
* __block修饰
* 使用对象封装
## 关于block作为属性时的修饰词(copy, strong)


