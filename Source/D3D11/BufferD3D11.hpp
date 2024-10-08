// © 2021 NVIDIA Corporation

#pragma region[  Core  ]

static void NRI_CALL SetBufferDebugName(Buffer& buffer, const char* name) {
    ((BufferD3D11&)buffer).SetDebugName(name);
}

static uint64_t NRI_CALL GetBufferNativeObject(const Buffer& buffer) {
    if (!(&buffer))
        return 0;

    return uint64_t((ID3D11Buffer*)((BufferD3D11&)buffer));
}

static void* NRI_CALL MapBuffer(Buffer& buffer, uint64_t offset, uint64_t size) {
    MaybeUnused(size);
    return ((BufferD3D11&)buffer).Map(offset);
}

static void NRI_CALL UnmapBuffer(Buffer& buffer) {
    ((BufferD3D11&)buffer).Unmap();
}

#pragma endregion

Define_Core_Buffer_PartiallyFillFunctionTable(D3D11);
