#ifndef _SRV_STATE_HXX_
#define _SRV_STATE_HXX_

namespace cornerstone {
    class srv_state {
    public:
        srv_state()
            : term_(0L), commit_idx_(0L), voted_for_(-1) {}

        __nocopy__(srv_state)

    public:
        ulong get_term() const { return term_; }
        void set_term(ulong term) { term_ = term; }
        ulong get_commit_idx() const { return commit_idx_; }
        void set_commit_idx(ulong commit_idx) { commit_idx_ = commit_idx; }
        int get_voted_for() const { return voted_for_; }
        void set_voted_for(int voted_for) { voted_for_ = voted_for; }
        void inc_term() { term_ += 1; }
    private:
        ulong term_;
        ulong commit_idx_;
        int voted_for_;
    };
}

#endif
