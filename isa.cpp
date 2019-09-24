struct __block_1_block_impl_0 {
  struct __block_impl impl;
  struct __block_1_block_desc_0* Desc;
  __block_1_block_impl_0(void *fp, struct __block_1_block_desc_0 *desc, int flags=0) {
    impl.isa = &_NSConcreteGlobalBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __block_1_block_func_0(struct __block_1_block_impl_0 *__cself) {
}

static struct __block_1_block_desc_0 {
  size_t reserved;
  size_t Block_size;
} __block_1_block_desc_0_DATA = { 0, sizeof(struct __block_1_block_impl_0)};
static __block_1_block_impl_0 __global_block_1_block_impl_0((void *)__block_1_block_func_0, &__block_1_block_desc_0_DATA);
void(*block_1)(void) = ((void (*)())&__global_block_1_block_impl_0);



struct __func_2_block_impl_0 {
  struct __block_impl impl;
  struct __func_2_block_desc_0* Desc;
  __func_2_block_impl_0(void *fp, struct __func_2_block_desc_0 *desc, int flags=0) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __func_2_block_func_0(struct __func_2_block_impl_0 *__cself) {
}

static struct __func_2_block_desc_0 {
  size_t reserved;
  size_t Block_size;
} __func_2_block_desc_0_DATA = { 0, sizeof(struct __func_2_block_impl_0)};
void func_2() {
    void(*block_2)(void) = ((void (*)())&__func_2_block_impl_0((void *)__func_2_block_func_0, &__func_2_block_desc_0_DATA));
    ((void (*)(__block_impl *))((__block_impl *)block_2)->FuncPtr)((__block_impl *)block_2);
}


struct __func_3_block_impl_0 {
  struct __block_impl impl;
  struct __func_3_block_desc_0* Desc;
  __func_3_block_impl_0(void *fp, struct __func_3_block_desc_0 *desc, int flags=0) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __func_3_block_func_0(struct __func_3_block_impl_0 *__cself) {
}

static struct __func_3_block_desc_0 {
  size_t reserved;
  size_t Block_size;
} __func_3_block_desc_0_DATA = { 0, sizeof(struct __func_3_block_impl_0)};

struct __func_3_block_impl_1 {
  struct __block_impl impl;
  struct __func_3_block_desc_1* Desc;
  struct __block_impl *block_3;
  __func_3_block_impl_1(void *fp, struct __func_3_block_desc_1 *desc, void *_block_3, int flags=0) : block_3((struct __block_impl *)_block_3) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __func_3_block_func_1(struct __func_3_block_impl_1 *__cself) {
  void (*block_3)() = (void (*)())__cself->block_3; // bound by copy

        ((void (*)(__block_impl *))((__block_impl *)block_3)->FuncPtr)((__block_impl *)block_3);
    }
static void __func_3_block_copy_1(struct __func_3_block_impl_1*dst, struct __func_3_block_impl_1*src) {_Block_object_assign((void*)&dst->block_3, (void*)src->block_3, 7/*BLOCK_FIELD_IS_BLOCK*/);}

static void __func_3_block_dispose_1(struct __func_3_block_impl_1*src) {_Block_object_dispose((void*)src->block_3, 7/*BLOCK_FIELD_IS_BLOCK*/);}

static struct __func_3_block_desc_1 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __func_3_block_impl_1*, struct __func_3_block_impl_1*);
  void (*dispose)(struct __func_3_block_impl_1*);
} __func_3_block_desc_1_DATA = { 0, sizeof(struct __func_3_block_impl_1), __func_3_block_copy_1, __func_3_block_dispose_1};
void func_3() {
    void(*block_3)(void) = ((void (*)())&__func_3_block_impl_0((void *)__func_3_block_func_0, &__func_3_block_desc_0_DATA));
    dispatch_after(dispatch_time((0ull), (int64_t)(0.3 * 1000000000ull)), dispatch_get_main_queue(), ((void (*)())&__func_3_block_impl_1((void *)__func_3_block_func_1, &__func_3_block_desc_1_DATA, (void *)block_3, 570425344)));
}
