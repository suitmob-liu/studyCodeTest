#include <iostream>

using namespace std;

//=================冒泡排序=================
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

//=================选择排序=================
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

//=================插入排序=================
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

//=================快速排序=================
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
	//基准数据 
	int key = array[i];
	while (i < j) {
		//因为默认基准是从左边开始，所以从右边开始比较 
		//当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针 
		while (i < j && array[j] >= key) {
			j--;
		}
		//当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它 
		if (i < j) {
			array[i] = array[j];
		}
		//当队首元素小于等于基准数据 时,就一直向后挪动 i 指针 
		while (i < j && array[i] <= key) {
			i++;
		}
		//当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
		if (i < j) {
			array[j] = array[i];
		}
	}
	//跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
	//把基准数据赋给正确位置 
	array[i] = key;
	return i;
}

void QuickSort(int array[], int low, int high) {
	//开始默认基准为 low
	if (low >= high)
	{
		return;
	}

	//分段位置下标 
	int standard = getStandard(array, low, high);
	//递归调用排序
	//左边排序 
	QuickSort(array, low, standard - 1);
	//右边排序 
	QuickSort(array, standard + 1, high);
}

//=================堆排序=================
//将i节点为根的堆中小的数依次上移,n表示堆中的数据个数
void MaxHeapInfy(int* a, int i, int n)
{
	int l = 2 * i + 1;//i的左儿子
	int r = 2 * i + 1;//i的右儿子

	int largest = i;//先设置父节点和子节点三个节点中最大值的位置为父节点下标
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

		MaxHeapInfy(a, largest, n);  //递归调用，保证子树也是最大堆		
	}
}

void BuildMaxHeap(int* a, int n)  //建立最大堆

{
	// 从最后一个非叶子节点（n/2-1）开始自底向上构建，
	for (int i = n / 2 - 1; i >= 0; i--)  //从（n/2-1）调用一次maxHeapIfy就可以得到最大堆

		MaxHeapInfy(a, i, n);

}

void Heap_Sort(int* a, int n)
{
	BuildMaxHeap(a, n);

	for (int i = n - 1; i > 0; i--)
	{
		// 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
		swap(a[0], a[i]);
		// 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。
		MaxHeapInfy(a, 0, i);
	}
}

int main(void)
{
	cout << "hello world！" << endl;
	return 0;
}