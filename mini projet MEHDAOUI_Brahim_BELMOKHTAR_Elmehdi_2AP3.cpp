//MEHDAOUI Brahim - 2AP3
//BELMOKHTAR Elmehdi - 2AP3
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//les structures
typedef struct symptome
{
	int num;
	struct symptome* suiv;
	
}symptome, *Maladie;

//Question 1

//////Fonction d'ajout Debut des symptomes/////
Maladie ajoutDebutM (Maladie l,int i)
{
	Maladie l1=(symptome *)malloc(sizeof(Maladie));
    l1->num=i;
    
	
		l1->suiv=l;
		return l1;
	

}


//test affichage symptomes
void AfficheM (Maladie L)
{
    printf("les symptomes sont: \n");
    
    while (L!=NULL)
    {
        printf("[Num :%d]; ",L->num);
        L=L->suiv;
    }
    
    if (L==NULL)
    {
        printf("-> Fin Des Symptomes \n");
        
    }
}

//Question 2

/////Fonction de suppression du doublement/////
Maladie SuppDoubl (Maladie l)
{
	int i;
	
	if (l==NULL)
	return NULL;
	
	else if (l->suiv==NULL)
	return l;
	
	else
	{
		Maladie l1,l2,l3=NULL;
		l1=l;
	
     	while(l1!=NULL)
		{ i=0;
			  
			    l2=l1->suiv;
			     
			     while(l2!=NULL)
			     {
			     	if (l1->num==l2->num)
                      i++;
			     	  
			     	  l2=l2->suiv;
				 }
				 
				 if(i==0)
				 l3 = ajoutDebutM (l3,l1->num);
				
               	l1=l1->suiv;         
		}
		
	
	
	return l3;
}}

//Question 3

//////Fonction trie en ordre croissant/////
Maladie TrieCroissant (Maladie l)
{
	if (l==NULL)
	return NULL;
	
	else if(l->suiv==NULL)
	return l;
	
	else{ Maladie l2;
	      int i,n;
		
		do{
			i=0;
			l2=l;
			
			while(l2->suiv!=NULL)
			{
				if(l2->num>l2->suiv->num)
				{
					n=l2->num;
					l2->num=l2->suiv->num;
					l2->suiv->num=n;
					i++;
				}
				
				l2=l2->suiv;
			}
		}while(i!=0);
		
		return l;
	}
}

//Question 4

/////////Fonction d'insert d'un entier/////

Maladie InserInt (Maladie l,int n)
{
	Maladie l1=(symptome *)malloc(sizeof(Maladie));
    l1->num=n;
    
    if(l==NULL)
    return l1;
    

	
	else{
		
	        Maladie l2=l;
	        int i=0;
	        
	        while(l2!=NULL)
			{
				if(n<l2->num && i==0)
				l2=NULL;
				
				else{
				
				if(l2->num==n)
				i++;
				
				l2=l2->suiv;}
			}
			
			if(i==0)
			{
			  l=ajoutDebutM (l,n);
              return l;	
			}
			
	   else
        {
		printf("la valeur deja existe \n");
        return l;
		}
	}
	
}

//Question 5

//////Fonction de ressemblance///

int Rassemblance(Maladie l,Maladie li)
{
	if(l==NULL || li==NULL)
	return 0;
	
	else {
		    Maladie l1,l2;
		    l1=l;l2=li;
		    int i=0;
		    
		    while(l1!=NULL)
		    {l2=li;
		    	   while(l2!=NULL)
		    	   {
		    	   	  if(l1->num==l2->num)
		    	   	  {
						 i++;
						 l2=NULL;}
						 
		    	   	  else
		    	   	  l2=l2->suiv;
				   }
				   
				   l1=l1->suiv;
			}
			
			return i;
	}}
	
	
//Question 6

//defintion du structure maladies (liste des maladies)///
typedef struct maladies
{
	
	symptome* symptomes;
	struct maladies* suiv;
	
} maladies, *listeM;	

//////Fonction d'ajout Debut des maladies/////
listeM ajouterDebutML (listeM l)
{
	listeM l1=(maladies *)malloc(sizeof(listeM));
	Maladie l2=NULL;

	int i=0,j,cmpt=0;
	
	while(i==0)
     {  
        printf("entrer le numero du symptome %d \n",cmpt);
        scanf("%d",&j);
     	l2=ajoutDebutM (l2,j);
     	printf("voulez vous ajouter une autre maladie (taper 0 pour oui et 1 pour non )\n");
     	scanf("%d",&i);
        cmpt++;
     	
	 }
	 l1->symptomes=l2;
	 
	 l1->suiv=l;
	 return l1;
	
}

//////Fonction de premiere base de diagnostic//////
Maladie Diagnostic(listeM l, Maladie li)
{
	if(l==NULL || li==NULL)
	return NULL;
	
	else{
		
		   int t[50],i=1,max;
		   listeM l1=l;
		   Maladie lm;
		   t[0]=0;
		   
		   while(l1!=NULL)
		   {
		   	 t[i]= Rassemblance(l1->symptomes,li);
		   	 
		   	 if(t[i]>t[i-1])
		   	 lm=l1->symptomes;
		   	 
		   	 i++;
		   	 l1=l1->suiv;
		   }
		   
		  return lm;
	}		
	
}

//test affichage maladies
void AfficheMS (listeM L)
{
    int i=1;

    while (L!=NULL)
    {
    	printf("\n\n ********* Maladie *********\n");
        AfficheM(L->symptomes);
        i++;
        L=L->suiv;
        
    }
    
    if (L==NULL)
    {
        printf("Fin Des Maladies \n");
        
    }
}

main()
{
    //Creation des listes et l'initialisation par NULL
	Maladie l2=NULL;
	Maladie l1=NULL;
	listeM l3=NULL;
	
	//remplissage de la lite des maladies (suite de symptoms) L3
	printf("\n\n ******remplissage de la lite des maladies (suite de symptoms) \n\n ");
	printf("-----------MALADIE X---------------\n");
	l3= ajouterDebutML(l3);
	printf("-----------MALADIE Z---------------\n");
	l3= ajouterDebutML(l3);

	
	//remplissage de la liste des symptomes L2
	l2 = ajoutDebutM (l2,4);
	l2 = ajoutDebutM (l2,3);
	l2 = ajoutDebutM (l2,2);
	l2 = ajoutDebutM (l2,1);
	
	//remplissage de la liste des symptomes L1
	l1 = ajoutDebutM (l1,4);
	l1 = ajoutDebutM (l1,3);
	l1 = ajoutDebutM (l1,1);
	
	//affichages des listes des symptomes
	printf("\n\n ******affichages des listes des symptomes \n\n");
	AfficheM (l2);
	AfficheM (l1);
	
	//traitement du suppresion du doublement dans la liste des symptomes
	printf("\n\n ******traitement du suppresion du doublement dans la liste des symptomes \n\n");
	l2= SuppDoubl (l2);
	printf("\n\nApres suppression \n");
	AfficheM (l2);
	
	//traitement de trie en ordre croissant
	printf("\n\n ******traitement de trie en ordre croissant \n\n");
	l2=TrieCroissant (l2);
	printf("\n\nApres trie \n");
	AfficheM (l2);
	
	//traitement d'insertion
	printf("\n\n ******traitement d'insertion \n\n");
	printf("\n\nApres insertion \n");
	l2 = InserInt (l2,1);
	AfficheM (l2);
	
	//Rassemblance entre les 2 maladies et liste des symptomes l1
	printf("\n\n ******Rassemblance entre les 2 maladies et liste des symptomes l1 (liste saisie 2 des symptomes) \n\n ");
	l1= SuppDoubl (l1);
	printf("\n\nRassemblance entre les 2 listes est : %d \n",Rassemblance(l1,l2));
	
	//Affichage des maladies
	printf("\n\n ******Affichage des maladies \n\n");
	printf("\n\n\n MALADIES \n");
	AfficheMS(l3);
	
	//traitement de prmier diagnostic
	printf("\n\n ******traitement de premier diagnostic \n\n");
	Maladie lp=NULL;
	lp=Diagnostic(l3,l1);
	printf("\n\nPremier Diagnostic \n");
	AfficheM (lp);
	
}
