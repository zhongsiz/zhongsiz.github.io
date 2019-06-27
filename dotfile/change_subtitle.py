#!/usr/bin/env python
import codecs
import sh
import re

note_path = '/home/zhongsiz/subler.github.io/note'
md_set = sh.find(note_path, '-name', '*.md')
print md_set


def mon_convert(mon_str):
    if mon_str == 'Dec':
        return '12'
    elif mon_str == 'Nov':
        return '11'
    elif mon_str == 'Otc' or mon_str == 'Oct':
        return '10'
    elif mon_str == 'Sep':
        return '09'
    elif mon_str == 'Aug':
        return '08'
    elif mon_str == 'Jul':
        return '07'
    elif mon_str == 'Jun':
        return '06'
    elif mon_str == 'May':
        return '05'
    elif mon_str == 'Apr' or mon_str == 'Apri':
        return '04'
    elif mon_str == 'Mar':
        return '03'
    elif mon_str == 'Feb':
        return '02'
    elif mon_str == 'Jan':
        return '01'

for md in md_set:
    date_pattern = r'(\d{2}) (\D{3,4}) (\d{4})'
    with codecs.open(md.strip('\n'), 'r+', encoding='UTF-8') as file:
        data = file.readlines()
        sm = re.search(date_pattern, data[3])
        while sm:
            # print data[3]
            # print sm.group()
            # print sm.group(1)
            # print sm.group(2)
            # print sm.group(3)
            data[3] = re.sub(sm.group(),
                             '-'.join([sm.group(3), mon_convert(sm.group(2)),
                                       sm.group(1)]),
                             data[3])
            sm = re.search(date_pattern, data[3])
            print data[3]
            file.seek(0, 0)
            file.writelines(data)
