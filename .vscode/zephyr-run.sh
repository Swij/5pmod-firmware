#!/bin/bash
set -eo pipefail
shopt -s extglob

SCRIPT_DIR="$(realpath "$(dirname "${BASH_SOURCE[0]}")")"

if [ $# -ne 1 ]; then
    cat <<EOF
Error: Invalid number of arguments ($#)
Usage: zephyr-run.sh COMMAND
EOF
    exit 1
fi

source "$SCRIPT_DIR/../../zephyr/zephyr-env.sh"

eval "$1"

exit
