#ifndef _STATE_MGR_HXX_
#define _STATE_MGR_HXX_

namespace cornerstone {
	class state_mgr {
	public:
		state_mgr() {}
		virtual ~state_mgr() {}

		__nocopy__(state_mgr)

	public:
		virtual cluster_config* load_config() = 0;
		virtual void save_config(const cluster_config* config) = 0;
		virtual void save_state(const srv_state* state) = 0;
		virtual srv_state* read_state() = 0;
		virtual log_store* load_log_store() = 0;
		virtual int server_id() = 0;
	};
}

#endif //_STATE_MGR_HXX_