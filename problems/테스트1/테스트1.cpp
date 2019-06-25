#include <stdio.h>

void Eratos(int n)
{
    /*  ���� n�� 1���� �۰ų� ������ �Լ� ���� */
    if (n <= 1) return;
    
    /*	2���� n���� n-1���� ������ �� �ִ� �迭 �Ҵ�
		�迭 ���� ��ȣ�� �Ҽ��� ��ġ�ϵ��� �迭�� ũ���
		n+1 ���̸�ŭ �Ҵ�(�ε��� ��ȣ 0�� 1�� ������� ����)	*/
	bool* PrimeArray = new bool[n + 1];

	/*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
	for (int i = 2; i <= n; i++) 
	    PrimeArray[i] = true;
	    
	/*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
		����, PrimeArray[i]�� true�̸� i ������ i ����� ����� i�� 
		������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
		PrimeArray[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
		�Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
			    PrimeArray[j] = false;
	}

	// ������ �۾� ...
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",Eratos(n));
}
