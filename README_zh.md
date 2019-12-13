# NEIE-Assistant
一个小巧、跨平台的NEIE辅助程序。

## 简介
我们在Github上用VB写了一个 [project](https://github.com/ranulldd/NEIE-Assistant) , 但由于VB的平台依赖性，它难以在除Windows外的平台上运行，所以我们决定来制作这个程序。

## 快速上手

命令行或终端中输入：
```
git clone https://github.com/LiangYuxuan/NEIE-Assistant.git
cd NEIE-Assistant

# 例：如果你已经激活了读写译，使用下面的命令开始：
python main.py -s example.com:1234 -u username -p password -l 4 -t rwt

# 例：如果你需要激活视听说，输入下面的命令以继续：
python main.py -ac -s example.com:1234 -u username -p password -l 4 -t vls
```

修改 `example.com:1234` `username` `password` `4` 为你的真实配置（分别为服务器的地址与端口，用户名，密码，需要刷的level）。对于level, `1 2 3 4` 分别代表 `A B C D`。

下一次运行，只需要命令行输入 `python main.py`.

### 用法
```
usage: main.py [-h] [-s PATH] [-u USERNAME] [-p PASSWORD] [-t TYPE] [-l LEVEL]
               [-ac] [-nf] [--end-unit END_UNIT] [--min-time MIN_TIME]
               [--max-time MAX_TIME] [--min-mark MIN_MARK]
               [--max-mark MAX_MARK]

A small, cross-platform program for NEIE.

optional arguments:
  -h, --help            显示这个帮助内容并退出
  -s PATH, --path PATH  服务器路径，包含ip地址和端口（一般情况下是80）
  -u USERNAME, --username USERNAME
                        登录用户名
  -p PASSWORD, --password PASSWORD
                        登录密码
  -t TYPE, --type TYPE  rwt or vls
  -l LEVEL, --level LEVEL
                        需要刷的level
  -ac, --activation     先尝试激活用户
  -nf, --no-file        不使用也不保存 config.json 中记录的上次使用的配置
  --end-unit END_UNIT   设置停在哪个unit
  --min-time MIN_TIME   设置刷过一个unit的最少时间，默认为60 （单位为秒，下同）
  --max-time MAX_TIME   设置刷过一个unit的最大用时，默认为120
  --min-mark MIN_MARK   设置刷过的unit的最少得分，默认为80
  --max-mark MAX_MARK   设置刷过的unit的最大得分，默认为100
```
**请注意: 您的登录信息会被明文储存在本目录下的 config.json 除非您设置了选项参数 '-nf'/'--no-file'。 但若您的登录信息被保存在 config.json 中,您下次运行本脚本就不需要添加选项参数。**

## 贡献
我们可以接受第三方编辑代码。每个人都可以 fork 这个项目并且发布 pull request.

## 版权
我们采用了开源项目 [requests](https://github.com/kennethreitz/requests) 和 [termcolor](https://pypi.python.org/pypi/termcolor).

NEIE-Assistant 在 GNU General Public License v3.0 的许可下开源.
