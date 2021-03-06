#!/usr/bin/env bash

allre=()

for f in ../.dat/*.dat; do

    d=../`basename ${f%.dat}`
    mkdir -p "$d"

    i=0
    while read l; do

        [ -z "$l" ] && continue
        set $l
        [ "$1" == SAME ] && continue

        i=$((i + 1))
        x=`printf '%02d' $i`.re

        rm -f "$d/$x"

        found=0
        for j in `seq ${#allre[@]}`; do
            if [ "${allre[j]}" == "$1" ]; then
                found=1
                break
            fi
        done
        [ $found == 1 ] && continue
        allre+=("$1")

        regexp=`printf "%s" "$1" | sed \
            -e 's/\[^/[^\\\\x00/g' \
            -e 's/\./[^\\\\x00]/g' \
            -e 's/()/("")/g'`

        printf '// re2c $INPUT -o $OUTPUT -i --flex-syntax\n' > "$d/$x"
        cat template | sed "s/<<<<REGEXP>>>>/$regexp/" > tmp
        cat tmp >> "$d/$x"
        rm tmp

    done < "$f"
done

