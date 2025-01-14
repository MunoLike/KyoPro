import os
import glob
import time
from datetime import datetime, timezone, timedelta
import shutil

template_list = glob.glob("./*/*/*.cpp", recursive=True)
timestamp = time.mktime(datetime(2024, 1, 1, tzinfo=timezone(timedelta(hours=9))).timetuple())

for file in template_list:
    shutil.copy(r".acc/cpp/main.cpp", file)