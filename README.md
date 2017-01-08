# NEIE-Assistant
A small, cross-platform program for NEIE.

## Developing
We found a [project](https://github.com/ranulldd/NEIE-Assistant) on github which is coded by Visual Basic, but it is hard to run on all platform expect Windows. So we decided to make this program.

### Process
We finished the basic function of the software.

The next plan is to make it easier to use.


### Usage
usage: main.py [-h] [-s SERVER] [-u USERNAME] [-p PASSWORD] [-l LEVEL]
               [-nf NO_FILE]

optional arguments:
  -h, --help            show this help message and exit
  -s SERVER, --server SERVER
                        the server ip
  -u USERNAME, --username USERNAME
                        your student ID
  -p PASSWORD, --password PASSWORD
                        your password
  -l LEVEL, --level LEVEL
                        your current level
  -nf NO_FILE, --no-file NO_FILE
                        whether build the config.json to record your
                        information,default is False
**If you didn't use `-n` & the first time to run ,you information will be recorded in `./config.json` by CLEAR TEXT.After that,you can simply use `python main.py` to run.**


## Contributing
We are free to accept to any code. Everyone can fork it and pull request.

## Copyright
We use open-source project including [requests](https://github.com/kennethreitz/requests) and [termcolor](https://pypi.python.org/pypi/termcolor).
