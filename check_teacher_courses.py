#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os

def read_file(filepath):
    """读取文件并尝试多种编码"""
    encodings = ['gbk', 'gb2312', 'utf-8', 'latin-1']
    for encoding in encodings:
        try:
            with open(filepath, 'r', encoding=encoding) as f:
                return f.read()
        except:
            continue
    return None

# 检查staff.txt中的教师授课信息
filepath = 'c:/Users/86191/Desktop/StudentManager/module_project2/staff.txt'
print("="*60)
print("staff.txt 内容（查看教师授课信息）")
print("="*60)
content = read_file(filepath)
if content:
    lines = content.strip().split('\n')
    for i, line in enumerate(lines[:15]):  # 显示前15行
        print(f"{i+1}: {line}")
    print(f"... 共 {len(lines)} 行")
else:
    print("无法读取文件")
