This is all note in work and life process
//
1. sử dụng array check giới hạn mảng khi sử dụng
E: f->data[f->wrIndex+i] // khi i++ ==> case: f->wrIndex+i > FIFO_SIZE
int pushFifo(fifo* f, int* dataIn, int length)
{
    if(isFull(f) || (length> FIFO_SIZE) || (length<= 0))
        return -1;
    for(int i =0; i<length; i++)
    {
        f->data[f->wrIndex+i] = dataIn[i];
    }
    
    // memcpy(&(f->data[f->wrIndex]), dataIn, length);
    f->wrIndex= (f->wrIndex +length)%FIFO_SIZE;
    f->count += length;
    return length; 
}

2. check code and case error before debug