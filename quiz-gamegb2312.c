#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 全局变量，用于题目编号
int question_number = 1;

// 生成随机的错误答案，根据运算符类型调整范围
int generate_wrong_answer(int correct_answer, char operation) {
    int wrong_answer;
    int range = (operation == '*') ? 100 : 20; // 乘法使用±100，其他使用±20

    do {
        wrong_answer = correct_answer + (rand() % (2 * range + 1) - range); // 在指定范围内生成错误答案
    } while (wrong_answer == correct_answer); // 确保错误答案与正确答案不同
    return wrong_answer;
}

void generate_question() {
    int num1, num2, correct_answer, wrong_answers[3];
    char operation;
    char options[] = {'a', 'b', 'c', 'd'};
    int correct_index;

    // 随机生成两个两位数
    num1 = rand() % 90 + 10; // 10 到 99
    num2 = rand() % 90 + 10; // 10 到 99

    // 随机选择运算符 (+, -, *)
    int op_type = rand() % 3;
    switch (op_type) {
        case 0:
            operation = '+';
            correct_answer = num1 + num2;
            break;
        case 1:
            operation = '-';
            correct_answer = num1 - num2;
            break;
        case 2:
            operation = '*';
            correct_answer = num1 * num2;
            break;
    }

    // 生成三个干扰答案，乘法使用±100的范围，其他使用±10
    for (int i = 0; i < 3; i++) {
        wrong_answers[i] = generate_wrong_answer(correct_answer, operation);
    }

    // 随机决定正确答案的选项位置
    correct_index = rand() % 4;

    // 输出题目，带有题目编号
    printf("题目 %d \n%d %c %d = ?\n", question_number, num1, operation, num2);
    for (int i = 0; i < 4; i++) {
        if (i == correct_index) {
            printf("%c) %d\n", options[i], correct_answer);
        } else {
            printf("%c) %d\n", options[i], wrong_answers[i < correct_index ? i : i - 1]);
        }
    }

    // 记录开始时间
    clock_t start_time = clock();

    // 获取用户输入并判断
    char user_choice;
    printf("请选择答案 (a, b, c, d): ");
    scanf(" %c", &user_choice);

    // 记录结束时间
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // 计算答题时间（秒）

    if (user_choice < 'a' || user_choice > 'd') {
        printf("退出程序...\n");
        exit(0);
    }

    if (user_choice == options[correct_index]) {
        printf("正确! 用时: %.2f 秒\n", time_taken);
    } else {
        printf("错误，正确答案是 %d. 用时: %.2f 秒\n", correct_answer, time_taken);
    }

    // 题目编号加1
    question_number++;
}

int main() {
    srand(time(NULL)); // 设置随机种子

    while (1) {
        generate_question(); // 生成并显示题目
        printf("\n");
    }

    return 0;
}
