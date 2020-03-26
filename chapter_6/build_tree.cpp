/*
 * @Description: 建树的问题总结
 * @Author: Xiaobin Ren
 * @Date: 2020-03-26 08:12:03
 * @LastEditTime: 2020-03-26 08:42:30
 */

/*
    关于先后中序建树的总结：
    参考：https://blog.csdn.net/Spidy_harker/article/details/88595011

    中序序列可以与先序，后序，层序序列中的任何一个建立一棵树，
    而后三者之间两两不能建树（因为无法区分根节点的左右子树）。
    换句话说， 只有找到了左子树和右子树的节点，才可以递归建树
    中序每次依靠先序/后序 ，在递归的子树中找到子树的根节点来建树

    步骤如下：
    1.判断空树，也就是出界条件
    2.根据后序/中序/层序找到树根的值，然后在中序中根据值找到树根的位置坐标
    3.递归左右子树完成
*/
#include <iostream>

using namespace std;

struct node
{
    int x;
    node* lson;
    node* rson;
};

int pre[1000],in[1000];

///二叉树的先序区间(prel,prer),中序区间(inl ,inr)
///通过先序区间找出根节点，可将中序区间分为左右子树，然后将左右子树看成单独的树
node* recreat(int prel,int prer,int inl, int inr)
{
    if(prel>prer) return NULL;///若先序区间长度<=0，则返回空，即没有子树
    node *root=new node;///建立根节点，并为其开辟空间
    root->x=pre[prel];///给根节点赋值
    int k;
    for(k=inl;k<inr;k++)///中序区间中找出根节点，这样就可以将先序序列分为左右子树
    {
        if(in[k]==pre[prel])///pre[prel]是根节点的值，为了将中序序列分为左右子树
            break;
    }
    int num=k-inl;///左子树的节点数目
    ///左子树的先序区间(pre+1,pre+1+num-1),中序区间(inl,k-1)
    root->lson=recreat(prel+1,prel+1+num-1,inl,k-1);///返回左子树的根节点root，赋给根节点的左儿子
    ///右子树的先序区间(pre+num+1,prer),中序区间(k+1,inr)
    root->rson=recreat(prel+1+num,prer,k+1,inr);///返回右子树的根节点root，赋给根节点的右儿子
    return root;
}

void post(node* Node)
{
    if(Node==NULL) return;
    post(Node->lson);
    post(Node->rson);
    cout<<Node->x<<" ";
}

int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];
    node* root=recreat(0,n-1,0,n-1);///注意区间是(0,n-1),不是(0,n);否则会多0出来
    post(root);
    return 0;
}

