xÑB                      @1×                            àe×        	             x0×                                                                        	                                               l2×                        ÿÿÿÿ                                               ×                                                                                          ÙHÖ        l2×              2×$3×                                  L                                                                                                                                                6         ü/×                                                                                                        ÿÿÿÿ                                                   Ð/×    ÿÿÿÿ               template < size_t _Align, class _Traits = _Default_allocate_traits,
    enable_if_t < ( ! 1 || _Align <= 16ULL ), int > = 0 >
__declspec ( allocator ) constexpr void * _Allocate ( const size_t _Bytes ) {



    if ( ! :: std :: is_constant_evaluated ( ) )

    {
        if ( _Bytes >= _Big_allocation_threshold ) {
            return _Allocate_manually_vector_aligned < _Traits > ( _Bytes );
        }
    }


    if ( _Bytes != 0 ) {
        return _Traits :: _Allocate ( _Bytes );
    }

    return nullptr;
}           PÙ×        X             TL×                   ×    LO×                                   L   .         ¨6× K×P5×P5×    M×               X6         ¨6×                                    Ô6×                                                                ÿÿÿÿ                                                   ðF×    ð5×     .                Ù¨¼£        ð5×             h7×                                   |E×hÐ                                                                                                                     ?×           Ü7×                                                                                                  àÛ        Ù    @  