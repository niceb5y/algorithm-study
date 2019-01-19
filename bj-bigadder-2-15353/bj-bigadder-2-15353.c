#include <stdio.h>
#include <string.h>

char input[10001]; // < 10^10000 (<=9999...9) (최대 1만 자리 + null 문자)
int operand[2][10000]; // 한자리씩 넣을 것이므로 char형이여도 무방하나, 연산속도를 위해서 int형 배열에 넣음
int lenA, lenB; // operand의 길이 (자릿수)
int lenC; // 결과값의 자리수
int result[10001] = {0, }; // 계산 결과는 최대 1만 1자리

/* input로부터 받은 Data를 operand에 '거꾸로' 넣고 자릿수를 len에 씀 */
void conv_array(const char *input, int operand[10000], int *len)
{
    int i = strlen(input);
    *len = i;
    while(i--) {
        operand[*len - i - 1] = input[i] - '0';
    }
}

/* 두 수를 계산한다. operand배열은 거꾸로 들어간 수, lenA, lenB는 피연산자 자릿수 // 리턴값은 결과값의 자리수 */
int add(int *result, const int operand1[10000], const int operand2[10000], const int lenA, const int lenB)
{
    int added;
    int lA = lenA;
    int lB = lenB;
    int i = 0;
    int carry = 0;
    while (lA && lB) {
        added = (operand1[i] + operand2[i] + carry) % 10;
        carry = (operand1[i] + operand2[i] + carry) / 10;
        result[i++] = added;
        lA--;
        lB--;
    }
    while (lA--) {
        added = (operand1[i] + carry) % 10;
        carry = (operand1[i] + carry) / 10;
        result[i++] = added;
    }
    while (lB--) {
        added = (operand2[i] + carry) % 10;
        carry = (operand2[i] + carry) / 10;
        result[i++] = added;
    }
    if(carry) result[i++] = carry;
    return i;
}

void print_inv(const int * result, const int len)
{
    int i = len;
    while(i--) {
        printf("%d", result[i]);
    }
}

int main(void)
{
    int i;
    scanf("%s", input);
    conv_array(input, operand[0], &lenA);
    scanf("%s", input);
    conv_array(input, operand[1], &lenB);
    lenC = add(result, operand[0], operand[1], lenA, lenB);
    print_inv(result, lenC);
    putchar('\n');

    return 0;
}

