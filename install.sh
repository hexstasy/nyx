#!/bin/bash

set -e
set -o pipefail

archive_name="LATEST.tar.gz"
libsodium_dir="libsodium-stable"

mkdir lib
cd lib

echo "[*] Downloading the libsodium archive..."
curl -L -O https://download.libsodium.org/libsodium/releases/$archive_name

echo "[+] Archive downloaded: $archive_name"

echo "[*] Extracting archive..."
tar -xf "$archive_name"

echo "[+] Archive extracted."

echo "[*] Configuring build..."
"./$libsodium_dir/configure"

echo "[*] Building libsodium..."
make && make check

echo "[*] Installing libsodium (as root)..."
sudo make install

rm -rf $archive_name
echo "[+] Done. libsodium installed."
