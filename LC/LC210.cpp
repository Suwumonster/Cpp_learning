#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//�γ̱�II���ţ�ͼ���͵����������㷨(Topological Sorting)
//���������õ�����
//1.�����ͼ�Ľṹ��ͼ���Ľṹ
//2.���Ӻ�ͼ�и������
//3.ѭ����������ͼ��㣬�����Ϊ0�Ľ��ѹ�������
//4.�Ӷ���ȡ����㣨������ڻ�·��������л��� �Ӷ�������ȡ���Ľ���� �� ͼ�еĽ���� һ������ȣ�
//5.ɾ���Ըõ�Ϊ��ʼ���ıߣ�ɾ���õ㣬ѭ����3.
class Node
{
public:
    Node(int Num = -1) :visit(0), courseNum(Num), prevNodes(vector<Node*>()), nextNodes(vector<Node*>()) {}
    bool isStartNode()
    {
        return prevNodes.size() == 0;
    }
    bool isEndNode()
    {
        return nextNodes.size() == 0;
    }
    void visited()
    {
        visit = 1;
    }
    int visit;
    int courseNum;
    vector<Node*> prevNodes;
    vector<Node*> nextNodes;
};

class Graph
{
public:
    Graph() {
        startNode = new Node;
    }
    ~Graph() {
        if (startNode)
        {
            for (int i = 0; i < startNode->nextNodes.size(); i++)
            {
                delete startNode->nextNodes[i];
            }
            delete startNode;
            startNode = nullptr;
        }
    }
    void AddNode(int courseNum)
    {
        Node* newNode = new Node(courseNum);
        startNode->nextNodes.push_back(newNode);
    }
    void CourseNumToConcat(int c1, int c2)
    {
        Node* n1 = nullptr;
        Node* n2 = nullptr;
        for (int i = 0; i < startNode->nextNodes.size(); i++)
        {
            if (c1 == (startNode->nextNodes[i]->courseNum))
            {
                n1 = startNode->nextNodes[i];
            }
            if (c2 == (startNode->nextNodes[i]->courseNum))
            {
                n2 = startNode->nextNodes[i];
            }
        }
        Concat(n1, n2);
    }
    void Concat(Node* n1, Node* n2)
    {
        n1->nextNodes.push_back(n2);
        n2->prevNodes.push_back(n1);
    }
    Node* startNode;
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> scheduledCourse;
        Graph g;
        for (int i = 0; i < numCourses; i++)
        {
            g.AddNode(i);
        }
        for (auto n : prerequisites)
        {
            g.CourseNumToConcat(n[1], n[0]);
        }

        queue<Node*> qu;
        for (auto n : g.startNode->nextNodes)
        {
            if (n->isStartNode())
            {
                qu.push(n);
                n->visited();
            }
        }
        while (!qu.empty())
        {
            Node* tmp = qu.front();
            qu.pop();
            scheduledCourse.push_back(tmp->courseNum);
            for (auto n : tmp->nextNodes)
            {
                auto delpos = find(n->prevNodes.begin(), n->prevNodes.end(), tmp);
                n->prevNodes.erase(delpos);
                if (n->visit == 0 && n->isStartNode())
                {
                    qu.push(n);
                    n->visited();
                }
            }
            
        }
        if (scheduledCourse.size() != numCourses)
        {
            return vector<int>();
        }
        return scheduledCourse;
    }
};

int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = { {0,1} ,{1, 0}, {0, 2} };
    Solution s;
    s.findOrder(numCourses, prerequisites);
    return 0;
}