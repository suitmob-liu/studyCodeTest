#include <iostream>

using namespace std;

//=================ð������=================
void Bubble_Sort(int* a, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//=================ѡ������=================
void Selection_Sort(int* a, int len)
{
	int minIndex;
	int temp;
	for (int i = 0; i < len - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
}

//=================��������=================
void Inser_Sort(int a[], int len)
{
	int j;
	int current;

	for (int i = 0; i < len; i++)
	{
		j = i;
		current = a[i];

		while (j >= 0 && a[j - 1] > current)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = current;
	}
}

//=================��������=================
void quickSort(int* a, int left, int right)
{
	if (left >= right) {
		return;
	}

	int base = a[((left + right) / 2)];
	int i = left;
	int j = right;

	while (i <= j)
	{
		while (a[i] < base) {
			i++;
		}

		while (a[j] > base) {
			j--;
		}

		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	quickSort(a, left, j);
	quickSort(a, i, right);
}

int getStandard(int array[], int i, int j) {
	//��׼���� 
	int key = array[i];
	while (i < j) {
		//��ΪĬ�ϻ�׼�Ǵ���߿�ʼ�����Դ��ұ߿�ʼ�Ƚ� 
		//����β��Ԫ�ش��ڵ��ڻ�׼���� ʱ,��һֱ��ǰŲ�� j ָ�� 
		while (i < j && array[j] >= key) {
			j--;
		}
		//���ҵ��� array[i] С��ʱ���ͰѺ����ֵ array[j] ������ 
		if (i < j) {
			array[i] = array[j];
		}
		//������Ԫ��С�ڵ��ڻ�׼���� ʱ,��һֱ���Ų�� i ָ�� 
		while (i < j && array[i] <= key) {
			i++;
		}
		//���ҵ��� array[j] ���ʱ���Ͱ�ǰ���ֵ array[i] ������
		if (i < j) {
			array[j] = array[i];
		}
	}
	//����ѭ��ʱ i �� j ���,��ʱ�� i �� j ���� key ����ȷ����λ��
	//�ѻ�׼���ݸ�����ȷλ�� 
	array[i] = key;
	return i;
}

void QuickSort(int array[], int low, int high) {
	//��ʼĬ�ϻ�׼Ϊ low
	if (low >= high)
	{
		return;
	}

	//�ֶ�λ���±� 
	int standard = getStandard(array, low, high);
	//�ݹ��������
	//������� 
	QuickSort(array, low, standard - 1);
	//�ұ����� 
	QuickSort(array, standard + 1, high);
}

//=================������=================
//��i�ڵ�Ϊ���Ķ���С������������,n��ʾ���е����ݸ���
void MaxHeapInfy(int* a, int i, int n)
{
	int l = 2 * i + 1;//i�������
	int r = 2 * i + 1;//i���Ҷ���

	int largest = i;//�����ø��ڵ���ӽڵ������ڵ������ֵ��λ��Ϊ���ڵ��±�
	if (l<n && a[l]>a[largest])
	{
		largest = i;
	}

	if (r<n && a[r]>a[largest])
	{
		largest = r;
	}

	if (largest != i)
	{
		swap(a[i], a[largest]);

		MaxHeapInfy(a, largest, n);  //�ݹ���ã���֤����Ҳ������		
	}
}

void BuildMaxHeap(int* a, int n)  //��������

{
	// �����һ����Ҷ�ӽڵ㣨n/2-1����ʼ�Ե����Ϲ�����
	for (int i = n / 2 - 1; i >= 0; i--)  //�ӣ�n/2-1������һ��maxHeapIfy�Ϳ��Եõ�����

		MaxHeapInfy(a, i, n);

}

void Heap_Sort(int* a, int n)
{
	BuildMaxHeap(a, n);

	for (int i = n - 1; i > 0; i--)
	{
		// �����ڵ�(���ֵ)����������򲿷ֵ����һ��Ԫ�ؽ���,�������յõ����ǵ�������
		swap(a[0], a[i]);
		// ���������鳤�ȼ�һ,ֻҪ�Ի������ڵ��Ԫ�ؽ������򣬽����³��ͺ��ˡ�
		MaxHeapInfy(a, 0, i);
	}
}

int main(void)
{
	cout << "hello world��" << endl;
	return 0;
}