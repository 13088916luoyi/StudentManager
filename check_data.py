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

# 检查各个文件
files = ['staff.txt', 'student.txt', 'module.txt', 'score.txt']
base_path = 'c:/Users/86191/Desktop/StudentManager/module_project2/'

for filename in files:
    filepath = os.path.join(base_path, filename)
    print(f"\n{'='*60}")
    print(f"文件: {filename}")
    print('='*60)
    content = read_file(filepath)
    if content:
        lines = content.strip().split('\n')
        # 打印前5行（包括标题）
        for i, line in enumerate(lines[:6]):
            print(f"{i+1}: {line}")
        print(f"... 共 {len(lines)} 行")
    else:
        print("无法读取文件")
