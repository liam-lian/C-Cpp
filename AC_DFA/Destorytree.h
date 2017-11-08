
void Destorytree( struct AC_Node *T ) {
    int i=0;
    if(T==NULL)
    	return;
 
    for(;i<16;i++){
    	if(T->child[i]!=NULL){
    		Destorytree(T->child[i]);
    	}
    }	
    free(T);
}
