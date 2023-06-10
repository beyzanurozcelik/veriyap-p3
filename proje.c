#include<stdio.h>
#include<stdlib.h>

struct node_m {
	int mno;
	int geldigidk;
	int islemdk;
	struct node_m *next;
};
struct queue {
	struct node_m *front;
	struct node_m *rear;
};
struct node_g {
	int no;
	int bitisdk;
	struct node_g *next;
};
struct node_m_son {
	int mno;
	int gno;
	int islembaslamadk;
	int islembitis;
	int bekleme;
	struct node_m_son *next;
};
struct node_g_son {
	int no;
	int toplamislem;
	struct node_g_son *next;
};

struct queue *createqueue() {
	struct queue *q = malloc(sizeof(struct queue));
	q->front = NULL;
	q->rear = NULL;
}
void insert(struct queue *q,int mno,int geldigidk,int islemdk) {
	struct node_m *newnode;
	newnode = malloc(sizeof(struct node_m));
	newnode->mno = mno;
	newnode->geldigidk = geldigidk;
	newnode->islemdk = islemdk;
	
	if (q->front == NULL) {
		q->front = newnode;
		q->rear = newnode;
		q->front->next = q->rear->next = NULL;
	}
	else {
		q->rear->next = newnode;
		q->rear = newnode;
		q->rear->next = NULL;
		
	}
}
void delete(struct queue *q) {
	struct node_m *temp;
	if (q->front != NULL) {
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
}
struct node_g *gorevlibul(struct node_g *head,struct node_m *musteri) {
	int geldigidk,c=0;
	geldigidk = musteri->geldigidk;
	struct node_g *temp,*temp2;
	temp = head;
	while (temp!=NULL) {
		if (temp->bitisdk <= geldigidk) {
			c = 1 ;
			temp2 = temp;
			break;
		}
		temp = temp->next;
	}
	temp = head;
	if (c==0) {
		struct node_g *hold = temp;
		temp = temp->next;
		while(temp!=NULL) {
			if ((hold->bitisdk) > (temp->bitisdk)) {
				hold = temp;
			}
			temp = temp->next;
		}
		temp2 = hold;
	}
	return temp2;
}
struct node_m_son *musterisonguncelle(struct node_m *musteri,struct node_g *gorevli,struct node_m_son *head) {
	int mno,gno,islembas,islembitis,bekledigi;
	
	mno = musteri->mno;
	gno = gorevli->no;
	
	if (musteri->geldigidk < gorevli->bitisdk) {
		bekledigi = gorevli->bitisdk - musteri->geldigidk;
	}
	else {
		bekledigi = 0;
	}
	islembas = musteri->geldigidk + bekledigi;
	islembitis = islembas + musteri->islemdk;
	
	
	struct node_m_son *temp = head;
	
	struct node_m_son *newnode;
	newnode = malloc(sizeof(struct node_m_son));
	
	if (head == NULL) {
		head = newnode;
		newnode -> next = NULL;
		newnode -> mno = mno;
		newnode->gno = gno;
		newnode->islembaslamadk = islembas;
		newnode->islembitis = islembitis;
		newnode->bekleme = bekledigi;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode -> next = NULL;
		newnode -> mno = mno;
		newnode->gno = gno;
		newnode->islembaslamadk = islembas;
		newnode->islembitis = islembitis;
		newnode->bekleme = bekledigi;
	}
	return head;
}
void gorevliguncelle(struct node_m *musteri,struct node_g *gorevli,struct node_g_son *head) {
	struct node_g_son  *temp = head;
	while (temp->no != gorevli->no) {
		temp = temp->next;
	}
	temp->toplamislem += musteri->islemdk;
}

void display(struct queue *q)
{
struct node_m *ptr;
ptr = q -> front;
if(ptr == NULL)
		
printf("\n QUEUE IS EMPTY");
else
{
		printf("\n");
while(ptr!=q -> rear)
		{
			printf("%d\t", ptr -> mno);
			ptr = ptr -> next;
		}
		printf("%d\t", ptr -> mno);
}

}	


int main() {
	struct queue *q = createqueue();
	
	struct node_g *g6;
	g6 = malloc(sizeof(struct node_g));
	g6->no = 6;
	g6->bitisdk = 0;
	
	struct node_g *g5;
	g5 = malloc(sizeof(struct node_g));
	g5 ->no = 5;
	g5->bitisdk = 0;
	
	struct node_g *g4;
	g4 = malloc(sizeof(struct node_g));
	g4->no = 4;
	g5->bitisdk = 0;
	
	struct node_g *g3;
	g3 = malloc(sizeof(struct node_g));
	g3->no = 3;
	g5->bitisdk = 0;
	
	struct node_g *g2;
	g2 = malloc(sizeof(struct node_g));
	g2->no = 2;
	g5->bitisdk = 0;
	
	struct node_g *g1;
	g1 = malloc(sizeof(struct node_g));
	g1->no = 1;
	g5->bitisdk = 0;
	
	g6->next = g5;
	g5->next = g4;
	g4->next = g3;
	g3->next = g2;
	g2->next = g1;
	g1->next = NULL;
	
	struct node_g_son *g66;
	g66 = malloc(sizeof(struct node_g_son));
	g66->no = 6;
	
	struct node_g_son *g55;
	g55 = malloc(sizeof(struct node_g_son));
	g55->no = 5;
	
	struct node_g_son *g44;
	g44 = malloc(sizeof(struct node_g_son));
	g44->no = 4;
	
	struct node_g_son *g33;
	g33 = malloc(sizeof(struct node_g_son));
	g33->no = 3;
	
	struct node_g_son *g22;
	g22 = malloc(sizeof(struct node_g_son));
	g22->no = 2;
	
	struct node_g_son *g11;
	g11 = malloc(sizeof(struct node_g_son));
	g11->no = 1;
	
	g66->next = g55;
	g55->next = g44;
	g44->next = g33;
	g33->next = g22;
	g22->next = g11;
	g11->next = NULL;
	
	struct node_g_son *temp = g66;
	while (temp != NULL) {
		temp->toplamislem = 0;
		temp = temp->next;
	}
	
	int musteri=1,gelme,islem;
	while(musteri != -1) {
		scanf("%d",&musteri);
		if (musteri != -1) {
			scanf("%d%d",&gelme,&islem);
			insert(q,musteri,gelme,islem);
		}
	}
	
	struct node_m *tempm;
	struct node_g *tempg;
	struct node_m_son *headmson=NULL;
	
	while (q->front != NULL) {
		tempm = q -> front;
		tempg = gorevlibul(g6,tempm);
	
		headmson = musterisonguncelle(tempm,tempg,headmson);
		
		gorevliguncelle(tempm,tempg,g66);
		
		tempg->bitisdk = tempm->geldigidk + tempm->islemdk;
		
		delete(q);
	}
	
	struct node_m_son *tempmson = headmson;
	struct node_g_son *tempgson = g66;
	while(tempmson != NULL) {
		printf("%d %d %d %d %d\n",tempmson->mno,tempmson->gno,tempmson->islembaslamadk,tempmson->islembitis,tempmson->bekleme);
		tempmson = tempmson->next;
	}
	printf("\n");
	while (tempgson != NULL) {
		printf("%d %d\n",tempgson->no,tempgson->toplamislem);
		tempgson = tempgson->next;
	}
	
	return 0;
}























