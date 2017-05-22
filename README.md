# NEIE-Assistant
A small, cross-platform program for NEIE.

## Introduction
We found a [project](https://github.com/ranulldd/NEIE-Assistant) on github which is coded by Visual Basic, but it is hard to run on all platform expect Windows. So we decided to make this program.

### Usage
```
usage: main.py [-h] [-s PATH] [-u USERNAME] [-p PASSWORD] [-l LEVEL] [-ac]
               [-nf] [--end-unit END_UNIT] [--min-time MIN_TIME]
               [--max-time MAX_TIME] [--min-mark MIN_MARK]
               [--max-mark MAX_MARK]

A small, cross-platform program for NEIE.

optional arguments:
  -h, --help            show this help message and exit
  -s PATH, --path PATH  path to server, may contain ip and port
  -u USERNAME, --username USERNAME
                        username to login
  -p PASSWORD, --password PASSWORD
                        password to login
  -l LEVEL, --level LEVEL
                        current level
  -ac, --activation     try to active user first
  -nf, --no-file        stop read and write information to config.json
  --end-unit END_UNIT   stop at a unit before all unit learned
  --min-time MIN_TIME   min time to learn a unit, default 60
  --max-time MAX_TIME   max time to learn a unit, default 120
  --min-mark MIN_MARK   min mark to learn a unit, default 80
  --max-mark MAX_MARK   max mark to learn a unit, default 100
```
**Please note: Your login information will be stored in config.json by CLEAR TEXT if you have no argument '-nf'/'--no-file'. Otherwise, if your information have stored in config.json, you can run main.py with no arguments next time.**

## Contributing
We are free to accept to any code. Everyone can fork it and pull request.

## Copyright
We use open-source project including [requests](https://github.com/kennethreitz/requests) and [termcolor](https://pypi.python.org/pypi/termcolor).

NEIE-Assistant is licensed under the GNU General Public License v3.0.
