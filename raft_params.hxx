#ifndef _RAFT_PARAMS_HXX_
#define _RAFT_PARAMS_HXX_

namespace cornerstone {
    struct raft_params {
    public:
        raft_params()
            : election_timeout_upper_bound_(300),
            election_timeout_lower_bound_(150),
            heart_beat_interval_(75),
            rpc_failure_backoff_(25),
            log_sync_batch_size_(1000),
            log_sync_stop_gap_(10),
            snapshot_distance_(0),
            snapshot_block_size_(0),
            max_append_size_(100) {}

        __nocopy__(raft_params)
    public:
        /**
        * Election timeout upper bound in milliseconds
        * @param timeout
        * @return self
        */
        raft_params& with_election_timeout_upper(int32 timeout) {
            election_timeout_upper_bound_ = timeout;
            return *this;
        }

        /**
        * Election timeout lower bound in milliseconds
        * @param timeout
        * @return self
        */
        raft_params& with_election_timeout_lower(int32 timeout) {
            election_timeout_lower_bound_ = timeout;
            return *this;
        }

        /**
        * heartbeat interval in milliseconds
        * @param hb_interval
        * @return self
        */
        raft_params& with_hb_interval(int32 hb_interval) {
            heart_beat_interval_ = hb_interval;
            return *this;
        }

        /**
        * Rpc failure backoff in milliseconds
        * @param backoff
        * @return self
        */
        raft_params& with_rpc_failure_backoff(int32 backoff) {
            rpc_failure_backoff_ = backoff;
            return *this;
        }

        /**
        * The maximum log entries could be attached to an appendEntries call
        * @param size
        * @return self
        */
        raft_params& with_max_append_size(int32 size) {
            max_append_size_ = size;
            return *this;
        }

        /**
        * For new member that just joined the cluster, we will use log sync to ask it to catch up,
        * and this parameter is to specify how many log entries to pack for each sync request
        * @param batch_size
        * @return self
        */
        raft_params& with_log_sync_batch_size(int32 batch_size) {
            log_sync_batch_size_ = batch_size;
            return *this;
        }

        /**
        * For new member that just joined the cluster, we will use log sync to ask it to catch up,
        * and this parameter is to tell when to stop using log sync but appendEntries for the new server
        * when leaderCommitIndex - indexCaughtUp < logSyncStopGap, then appendEntries will be used
        * @param gap
        * @return self
        */
        raft_params& with_log_sync_stopping_gap(int32 gap) {
            log_sync_stop_gap_ = gap;
            return *this;
        }

        /**
        * Enable log compact and snapshot with the commit distance
        * @param commit_distance, log distance to compact between two snapshots
        * @return self
        */
        raft_params& with_snapshot_enabled(int32 commit_distance) {
            snapshot_distance_ = commit_distance;
            return *this;
        }

        /**
        * The tcp block size for syncing the snapshots
        * @param size
        * @return self
        */
        raft_params& with_snapshot_sync_block_size(int32 size) {
            snapshot_block_size_ = size;
            return *this;
        }

        int max_hb_interval() const {
            return std::max(heart_beat_interval_, election_timeout_lower_bound_ - (heart_beat_interval_ / 2));
        }

    public:
        int32 election_timeout_upper_bound_;
        int32 election_timeout_lower_bound_;
        int32 heart_beat_interval_;
        int32 rpc_failure_backoff_;
        int32 log_sync_batch_size_;
        int32 log_sync_stop_gap_;
        int32 snapshot_distance_;
        int32 snapshot_block_size_;
        int32 max_append_size_;
    };
}

#endif //_RAFT_PARAMS_HXX_