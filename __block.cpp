struct __Block_byref_a_0 {
  void *__isa;
__Block_byref_a_0 *__forwarding;
 int __flags;
 int __size;
 int a;
};

struct __func_2_block_impl_0 {
  struct __block_impl impl;
  struct __func_2_block_desc_0* Desc;
  __Block_byref_a_0 *a; // by ref
  __func_2_block_impl_0(void *fp, struct __func_2_block_desc_0 *desc, __Block_byref_a_0 *_a, int flags=0) : a(_a->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static void __func_2_block_func_0(struct __func_2_block_impl_0 *__cself) {
  __Block_byref_a_0 *a = __cself->a; // bound by ref

        (a->__forwarding->a) = 2;

    }
static void __func_2_block_copy_0(struct __func_2_block_impl_0*dst, struct __func_2_block_impl_0*src) {_Block_object_assign((void*)&dst->a, (void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);}

static void __func_2_block_dispose_0(struct __func_2_block_impl_0*src) {_Block_object_dispose((void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __func_2_block_desc_0 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __func_2_block_impl_0*, struct __func_2_block_impl_0*);
  void (*dispose)(struct __func_2_block_impl_0*);
} __func_2_block_desc_0_DATA = { 0, sizeof(struct __func_2_block_impl_0), __func_2_block_copy_0, __func_2_block_dispose_0};
void func_2() {
    __attribute__((__blocks__(byref))) __Block_byref_a_0 a = {(void*)0,(__Block_byref_a_0 *)&a, 0, sizeof(__Block_byref_a_0), 1};
    void(*block_2)(void) = ((void (*)())&__func_2_block_impl_0((void *)__func_2_block_func_0, &__func_2_block_desc_0_DATA, (__Block_byref_a_0 *)&a, 570425344));
    ((void (*)(__block_impl *))((__block_impl *)block_2)->FuncPtr)((__block_impl *)block_2);
}
