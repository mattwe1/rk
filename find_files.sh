#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
  echo "Пожалуйста, укажите директорию и расширение файлов."
  exit 1
fi

directory=$1
extension=$2

if [ ! -d "$directory" ]; then
  echo "Директория не найдена."
  exit 1
fi

files=$(find "$directory" -type f -name "*.$extension")
if [ -z "$files" ]; then
  echo "Файлы с расширением $extension не найдены."
else
  echo "Найденные файлы с расширением .$extension:"
  echo "$files"
fi
