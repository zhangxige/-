# -
转化要求见README
c++实现java中特定字符串转换函数:
1.如果字符是小于0的字符，直接copy过来
2.如果是0-9的字符，且其后继字符为“_”或为字符串结尾，那么也直接copy过来
3.如果是0-9的字符n，且其后继字符存在(不为空也不为“_”)，那么将其后继字符复制过来并且个数为n+1
4.如果字符为_，那么copy过来为"\UL"
5.每个字符之间以“_”分隔
例如:
24ab_2t2  经过转化为
444_aaaaa_a_b_\UL_ttt_t_2
完成该变换及其逆变换
String code(const String input){
            return input;
}
String decode(const String input){
            return input;
}
