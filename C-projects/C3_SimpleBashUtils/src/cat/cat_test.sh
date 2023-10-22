var="$var1 $var2 $var3 $var4"


t="$var no_file.txt"
./s21_cat $t > res_s21_cat.txt
cat $t > res_cat.txt
diff res_cat.txt res_s21_cat.txt > res.txt
if [ -s "res.txt" ]
then
    echo "\033[31mfail\033[0m:$t"
else
    echo "\033[32msuccess\033[0m:$t"
fi


for var1 in ' ' '-b' '-e' '-n' '-s' '-t' '-v' 
do
    for var2 in ' ' '-b' '-e' '-n' '-s' '-t' '-v' 
    do
        for var3 in ' ' '-b' '-e' '-n' '-s' '-t' '-v' 
        do
            for var4 in ' ' '-b' '-e' '-n' '-s' '-t' '-v' 
            do
                var="$var1 $var2 $var3 $var4"

                t="$var bytes.txt"
                ./s21_cat $t > res_s21_cat.txt
                cat $t > res_cat.txt
                diff res_cat.txt res_s21_cat.txt > res.txt
                if [ -s "res.txt" ]
                then
                    echo "\033[31mfail\033[0m:$t"
                else
                    echo "\033[32msuccess\033[0m:$t"
                fi

                t="$var s21_cat.c"
                ./s21_cat $t > res_s21_cat.txt
                cat $t > res_cat.txt
                diff res_cat.txt res_s21_cat.txt > res.txt
                if [ -s "res.txt" ]
                then
                    echo "\033[31mfail\033[0m:$t"
                else
                    echo "\033[32msuccess\033[0m:$t"
                fi

            done
        done
    done
done


rm res_s21_cat.txt  res_cat.txt res.txt