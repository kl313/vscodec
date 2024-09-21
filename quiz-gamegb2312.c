#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ȫ�ֱ�����������Ŀ���
int question_number = 1;

// ��������Ĵ���𰸣�������������͵�����Χ
int generate_wrong_answer(int correct_answer, char operation) {
    int wrong_answer;
    int range = (operation == '*') ? 100 : 20; // �˷�ʹ�á�100������ʹ�á�20

    do {
        wrong_answer = correct_answer + (rand() % (2 * range + 1) - range); // ��ָ����Χ�����ɴ����
    } while (wrong_answer == correct_answer); // ȷ�����������ȷ�𰸲�ͬ
    return wrong_answer;
}

void generate_question() {
    int num1, num2, correct_answer, wrong_answers[3];
    char operation;
    char options[] = {'a', 'b', 'c', 'd'};
    int correct_index;

    // �������������λ��
    num1 = rand() % 90 + 10; // 10 �� 99
    num2 = rand() % 90 + 10; // 10 �� 99

    // ���ѡ������� (+, -, *)
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

    // �����������Ŵ𰸣��˷�ʹ�á�100�ķ�Χ������ʹ�á�10
    for (int i = 0; i < 3; i++) {
        wrong_answers[i] = generate_wrong_answer(correct_answer, operation);
    }

    // ���������ȷ�𰸵�ѡ��λ��
    correct_index = rand() % 4;

    // �����Ŀ��������Ŀ���
    printf("��Ŀ %d \n%d %c %d = ?\n", question_number, num1, operation, num2);
    for (int i = 0; i < 4; i++) {
        if (i == correct_index) {
            printf("%c) %d\n", options[i], correct_answer);
        } else {
            printf("%c) %d\n", options[i], wrong_answers[i < correct_index ? i : i - 1]);
        }
    }

    // ��¼��ʼʱ��
    clock_t start_time = clock();

    // ��ȡ�û����벢�ж�
    char user_choice;
    printf("��ѡ��� (a, b, c, d): ");
    scanf(" %c", &user_choice);

    // ��¼����ʱ��
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // �������ʱ�䣨�룩

    if (user_choice < 'a' || user_choice > 'd') {
        printf("�˳�����...\n");
        exit(0);
    }

    if (user_choice == options[correct_index]) {
        printf("��ȷ! ��ʱ: %.2f ��\n", time_taken);
    } else {
        printf("������ȷ���� %d. ��ʱ: %.2f ��\n", correct_answer, time_taken);
    }

    // ��Ŀ��ż�1
    question_number++;
}

int main() {
    srand(time(NULL)); // �����������

    while (1) {
        generate_question(); // ���ɲ���ʾ��Ŀ
        printf("\n");
    }

    return 0;
}
