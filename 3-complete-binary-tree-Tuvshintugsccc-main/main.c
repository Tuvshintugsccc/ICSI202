#include "DS.h"
#include <stdlib.h>

int main()
{
        /* Tree үүсгэн, эхлүүлэх */
        CBTree tr;
        tr.cb_len = 0;
        
        int t, x, pos, idx;

        while (1) {
                printf("1: insert, 2: height, 3: leaves, 4: descendants, 5: ancestors, "
                       "6: sibling, 7: children, 8: preorder, 9: inorder, 10: postorder, "
                       "11: size, 12: search, 13: level, 14: exit\n");
                scanf("%d", &t);

                switch (t) {
                case 1:
                        printf("Oruulax utga: ");
                        scanf("%d", &x);
                        cb_push(&tr, x);
                        break;
                case 2:
                        printf("Modnii undur: %d\n", cb_height(&tr));
                        break;
                case 3:
                        printf("Zangilaanii dugaariig oruul: ");
                        scanf("%d", &idx);
                        cb_leaves(&tr, idx);
                        break;
                case 4:
                        printf("Zangilaanii dugaariig oruul: ");
                        scanf("%d", &idx);
                        cb_descendants(&tr, idx);
                        break;
                case 5:
                        printf("Zangilaanii dugaariig oruul: ");
                        scanf("%d", &idx);
                        cb_ancestors(&tr, idx);
                        break;
                case 6:
                        printf("Zangilaanii dugaariig oruul: ");
                        scanf("%d", &idx);
                        printf("ax duugiin bairlal: %d\n", cb_sibling(&tr, idx));
                        break;
                case 7:
                        printf("Zangilaanii dugaariig oruul: ");
                        scanf("%d", &idx);
                        printf("1: left, 2: right\n");
                        scanf("%d", &t);
                        if (t == 1)
                                printf("Zuun: %d\n", cb_left(&tr, idx));
                        else
                                printf("Baruun: %d\n", cb_right(&tr, idx));
                        break;
                case 8:
                        cb_preorder(&tr, 0);
                        break;
                case 9:
                        cb_inorder(&tr, 0);
                        break;
                case 10:
                        cb_postorder(&tr, 0);
                        break;
                case 11:
                        printf("Xemjee: %d\n", cb_size(&tr));
                        break;
                case 12:
                        printf("Xaix utga oruul: ");
                        scanf("%d", &x);
                        pos = cb_search(&tr, x); 
                        if (pos != -1)
                                printf("%d utga %d bairlald oldloo\n", x, pos);
                        else
                                printf("%d utga oldsongui\n", x);
                        break;
                case 13:
                        printf("Utga oruul: ");
                        scanf("%d", &x);
                        printf("%d utgiin tuwshin: %d\n", x, cb_level(&tr, x));
                        break;
                default:
                        exit(0);
                }
        }
        return 0;
}
