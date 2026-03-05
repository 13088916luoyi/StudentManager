#!/usr/bin/env python3
# -*- coding: utf-8 -*-

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
print("staff.txt 内容（详细解析）")
print("="*60)
content = read_file(filepath)
if content:
    lines = content.strip().split('\n')
    for i, line in enumerate(lines):
        print(f"{i+1}: '{line}'")
        # 尝试不同的分割方式
        parts_tab = line.split('\t')
        parts_space = line.split()
        print(f"   制表符分割: {parts_tab}")
        print(f"   空格分割: {parts_space}")
        print()
else:
    print("无法读取文件")
