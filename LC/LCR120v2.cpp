//tips:0 ≤ documents[i] ≤ n-1
//n is element size
//所以如果没有副本的话，document本身就是个dic
//映射关系是 i == document[i]
//我们就可以用这种原地交换的方式，把 元素放在它应该在的位置 即 i == document[i]
//1.i == doc[i]  i++
//2.i != doc[i]  这种情况我们就需要把doc[i] 放在 下标为doc[i]的位置 即doc[doc[i]]
//   也就是swap(doc[i], doc[doc[i]]) 
//   但！！！！前提是我们需要判断 doc[doc[i]] == doc[i] ? 即 doc[i] 的位置 是否有一个正确的对应元素了！
//   如果有的话(==) 那表示 id为doc[i]的文件有副本 我们直接返回doc[i] 
//  又是一个化O（N^）为 O（n）的算法
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {//O(n) O(1)
        int sz = documents.size();
        for(int i = 0; i < sz;)
        {
            if(documents[i] == i)//元素在自己的位置上
            {
                i++;
            }
            else if(documents[documents[i]] == documents[i])//判断doc[i]位置是否存放对应元素
            {
                return documents[i];
            }
            else//没有存放对应元素，即没有副本，没有重复的。进行交换即可
            {
                swap(documents[documents[i]], documents[i]);
            }
        }
        return -1;
    }
};