#!/usr/bin/python3

import os
import argparse
import random
import string

def generate_random_text(word_count=200):
    words = []
    for _ in range(word_count):
        length = random.randint(3, 10)
        word = ''.join(random.choices(string.ascii_lowercase, k=length))
        words.append(word)
    return ' '.join(words)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
                prog = "./file_creation_script.py",
                description = "Creates n files in a given directory")
    parser.add_argument("dir", help = "child directory name where the files will be created", type=str)
    parser.add_argument("-n", "--number", help="number of files to be created", type=int, default=10)

    args = parser.parse_args()

    directory = args.dir
    number = args.number

    for i in range(1, number + 1):
        filename = os.path.join(directory, f"test{i}.txt")
        with open(filename, "w") as f:
            text = generate_random_text(200)
            f.write(text)
