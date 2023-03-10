#include "DS.h"
#include <math.h>


/*
  p-ийн зааж буй CBTree-д x утгыг оруулна
*/
void cb_push(CBTree *p, int x)
{
        /* Энд оруулах үйлдлийг хийнэ үү */
        p->tree.a[p->tree.len] = x;
        p->tree.len++;
}
/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны зүүн хүүгийн индексийг буцаана.
  Зүүн хүү байхгүй бол -1 буцаана.
*/
int cb_left(const CBTree *p, int idx)
{
        /* Энд зүүн хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
        if (idx * 2 + 1 < p->tree.len)
        {
                return idx * 2 + 1;
        }
        else
        {
                return -1;
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройны баруун хүүгийн индексийг буцаана.
  Баруун хүү байхгүй бол -1 буцаана.
*/
int cb_right(const CBTree *p, int idx)
{
        /* Энд баруун хүүхдийн индексийг буцаах үйлдлийг хийнэ үү */
        if (idx * 2 + 2 < p->tree.len)
        {
                return idx * 2 + 2;
        }
        else
        {
                return -1;
        }
}

/*
  p-ийн зааж буй CBTree-с x тоог хайн
  хамгийн эхэнд олдсон индексийг буцаана.
  Олдохгүй бол -1 утгыг буцаана.
*/
int cb_search(const CBTree *p, int x)
{
        /* Энд хайх үйлдлийг хийнэ */
        int i;
        for (i = 0; i < p->tree.len; i++)
        {
                if (p->tree.a[i] == x)
                {
                        return i;
                }
        }
        return -1;
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй зангилаанаас дээшхи бүх өвөг эцэгийг олох үйлдлийг хийнэ.
  Тухайн орой өөрөө өвөг эцэгт орохгүй.
  Өвөг эцэг бүрийг нэг шинэ мөрөнд хэвлэнэ. Өвөг эцэгийг доороос дээшхи дарааллаар хэвлэнэ.
*/
void cb_ancestors(const CBTree *p, int idx)
{
        /* Энд өвөг эцгийг олох үйлдлийг хийнэ үү */
        if (idx == 0)
        {
                return;
        }

        int i;
        for (i = idx; i > 0; i = (i - 1) / 2)
        {
                printf("%d\n", p->tree.a[(i - 1) / 2]);
        }
}

/*
  p-ийн зааж буй CBTree-ийн өндрийг буцаана
*/
int cb_height(const CBTree *p)
{
        /* Энд өндрийг олох үйлдлийг хийнэ */
        return ceil(log2(p->tree.len + 1));
}

/*
  p-ийн зааж буй CBTree-д idx оройны ах, дүү оройн дугаарыг буцаана.
  Тухайн оройн эцэгтэй адил эцэгтэй орой.
  Ах, дүү нь байхгүй бол -1-г буцаана.
*/
int cb_sibling(const CBTree *p, int idx)
{
        /* Энд ах, дүүг олох үйлдлийг хийнэ үү */
        if (idx == 0)
        {
                return -1;
        }
        int parent = (idx - 1) / 2;
        if (parent * 2 + 1 == idx)
        {
                if (parent * 2 + 2 < p->tree.len)
                {
                        return parent * 2 + 2;
                }
                else
                {
                        return -1;
                }
        }
        else
        {
                return parent * 2 + 1;
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн preorder-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_preorder(const CBTree *p, int idx)
{
        /* Энд pre-order-оор хэвлэх үйлдлийг хийнэ үү */
        if (idx < p->tree.len)
        {
                printf("%d\n", p->tree.a[idx]);
                cb_preorder(p, idx * 2 + 1);
                cb_preorder(p, idx * 2 + 2);
        }
}

/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн in-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
*/
void cb_inorder(const CBTree *p, int idx)
{
        /* Энд in-order-оор хэвлэх үйлдлийг хийнэ үү */
        if (idx < p->tree.len)
        {
                cb_inorder(p, idx * 2 + 1);
                printf("%d\n", p->tree.a[idx]);
                cb_inorder(p, idx * 2 + 2);
        }
}
/*
  p-ийн зааж буй CBTree-г idx дугаартай зангилаанаас эхлэн post-order-оор хэвлэ.
  Орой бүрийг нэг шинэ мөрөнд хэвлэнэ.
 */
void cb_postorder(const CBTree *p, int idx)
{
        /* Энд post-order-оор хэвлэх үйлдлийг хийнэ үү */
        if (idx < p->tree.len)
        {
                cb_postorder(p, idx * 2 + 1);
                cb_postorder(p, idx * 2 + 2);
                printf("%d\n", p->tree.a[idx]);
        }
}

/*
  p-ийн зааж буй CBTree-с idx дугаартай зангилаанаас доошхи бүх навчийг олно.
  Навч тус бүрийн утгыг шинэ мөрөнд хэвлэнэ.
  Навчыг зүүнээс баруун тийш олдох дарааллаар хэвлэнэ.
*/
void cb_leaves(const CBTree *p, int idx)
{
        /* Энд навчуудыг үйлдлийг хийнэ үү */
        if (idx < p->tree.len)
        {
                if (idx * 2 + 1 >= p->tree.len)
                {
                        printf("%d\n", p->tree.a[idx]);
                }
                cb_leaves(p, idx * 2 + 1);
                cb_leaves(p, idx * 2 + 2);
        }
}

/*
  p-ийн зааж буй CBTree-д idx индекстэй оройноос доошхи бүх үр садыг хэвлэнэ.
  Тухайн орой өөрөө үр сад болохгүй.
  Үр, сад бүрийг нэг шинэ мөрөнд хэвлэнэ. Үр садыг pre-order дарааллаар хэлэх ёстой.
*/
void cb_descendants(const CBTree *p, int idx)
{
        /* Энд үр садыг олох үйлдлийг хийнэ үү */
        if (idx < p->tree.len)
        {
                if (idx * 2 + 1 < p->tree.len)
                {
                        printf("%d\n", p->tree.a[idx * 2 + 1]);
                        cb_descendants(p, idx * 2 + 1);
                }
                if (idx * 2 + 2 < p->tree.len)
                {
                        printf("%d\n", p->tree.a[idx * 2 + 2]);
                        cb_descendants(p, idx * 2 + 2);
                }
        }
}


/*
  p-ийн зааж буй Tree-д хэдэн элемент байгааг буцаана.
  CBTree-д өөрчлөлт оруулахгүй.
*/
int cb_size(const CBTree *p)
{
        /* Энд хэмжээг олох үйлдлийг хийнэ үү */
        return p->tree.len;
}


/*
  p-ийн зааж буй CBTree-д x утгаас үндэс хүртэлх оройнуудын тоог буцаана.
  x тоо олдохгүй бол -1-г буцаана.
*/
int cb_level(const CBTree *p, int x)
{
        /* Энд түвшинг олох үйлдлийг хийнэ үү */
        int i;
        for (i = 0; i < p->tree.len; i++)
        {
                if (p->tree.a[i] == x)
                {
                        // printf("%f\n", ceil(log2(i + 2)) - 1);
                        return (int)ceil(log2(i + 2)) - 1;
                }
        }
        return -1;
}

