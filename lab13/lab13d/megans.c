void flexarray_sort(flexarray f) {

    int i, key, j, a;
    int size = f->itemcount;

    for (i = 1; i < size; i++){

        key = f->items[i];
        j = i-1;

        if(i==size/2){
            for(a = 0; a<size; a++){
                fprintf(stderr, "%d\n", f->items[a]);
            }
        }

        while (j >= 0 && f->items[j] > key){
            f->items[j+1] = f->items[j];
            j = j-1;
        }
        
        f->items[j+1] = key;
    }
    }